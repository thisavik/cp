// depth is same as level

#include <iostream>
#include <vector>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

const int maxN = 1e6;

vector<int> tree[maxN];

int depth[maxN];

void dfs(int s, int par)
{
    for(int child : tree[s])
    {
        if(child != par)
        {
            depth[child] = depth[s] + 1;
            dfs(child, s);
        }
    }
}

int32_t main()
{
    tool();
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    depth[1] = 0;
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << i << " -> " << depth[i] << "\n";
    cout << "\n";
    return 0;
}