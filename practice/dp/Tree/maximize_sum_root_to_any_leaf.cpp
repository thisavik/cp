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

const int maxN = 1e5;

vector<int> tree[maxN];
int dp[maxN], value[maxN];

void dfs(int s = 1, int par = 0)
{
    dp[s] = value[s];
    int mx = 0;
    for(int child : tree[s])
    {
        if(child != par)
        {
            dfs(child, s);
            mx = max(mx, dp[child]);
        }
    }
    dp[s] += mx;
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
    for(int i = 1; i <= n; i++)
        cin >> value[i];
    dfs();
    cout << dp[1];
}