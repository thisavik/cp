// we have given certain number of element and pairs
// we have to find maximum in each subset

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// using path compression
int Find(vector<int> &parent, int n)
{
    if (parent[n] < 0)
        return n;
    return parent[n] = Find(parent, parent[n]);
}

void Union(vector<int> &parent, int a, int b)
{
    a = Find(parent, a);
    b = Find(parent, b);
    if (a != b)
    {
        parent[a] = min(parent[a], parent[b]);
        parent[b] = a;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = -i;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        Union(parent, x, y);
    }
    for (int &val : parent)
        cout << val << " ";
    cout << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}