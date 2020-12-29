// we have given n node, with some node infected by certain diseases.
// also we have certain number of edges (u -> v)
// if any of node is infected then connection also infected
// we have to find how many nod eis infected at last.

#include <iostream>
#include <vector>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Find(int x, vector<int> &par)
{
    if (par[x] == -1)
        return x;
    return par[x] = Find(par[x], par);
}

int32_t main()
{
    tool();
    int n, m, k, l;
    cin >> n >> m;
    vector<int> par(n, -1), Rank(n, 1);
    bool ans[n] = {false};
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        ans[x] = true;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        int parX = Find(x, par);
        int parY = Find(y, par);
        // union
        if (parX != parY)
            par[parY] = parX;
        if (ans[x] || ans[y])
            ans[parX] = true;
    }
    for (int i = 0; i < n; i++) {
        int p = par[i];
        while(p != -1 && !ans[i]) {
            ans[i] = ans[p];
            p = par[p];
        } 
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x;
        cin >> x;
        if (ans[x])
            cout << "P\n";
        else
            cout << "NP\n";
    }
    return 0;
}