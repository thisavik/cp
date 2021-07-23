#include <iostream>
#include <vector>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int maxN = 1e6;

vector<int> tree[maxN];

int height[maxN];

void dfs(int s, int par)
{
    int h = 0;
    for(int child : tree[s])
    {
        if(child != par)
        {
            dfs(child, s);
            h = max(h, 1 + height[child]);
        }
    }
    height[s] = h;
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
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << i << " -> " << height[i] << "\n";
    cout << "\n";
    return 0;
}