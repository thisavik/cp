#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
const int maxN = 1e5+1;
int n;
vector<int> adj[101];
vector<int> ans;
void dfs(int s = 1, int par = 0)
{
    if(ans[s] == 0)
        ans[s] = 1;
    if(par != -1 && ans[par] == 1)
        ans[s] = 2;
    for(int child: adj[s])
        if(child != par)
            dfs(child, s);
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        rep(i, 101)
            adj[i].clear();
        ans.clear();
        cin >> n;
        rep(i, n+1)
            ans.push_back(0);
        int u, v, s;
        rep(i, n-1)
        {
            cin >> u >> v;
            adj[u].push_back(v), adj[v].push_back(u);
        }
        dfs();
        for(int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}