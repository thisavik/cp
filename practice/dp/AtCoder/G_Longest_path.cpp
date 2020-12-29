#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+1;
vector<int> adj[mxN];

int dp[mxN];
int dfs(int s)
{
    if(dp[s] != -1)
        return dp[s];
    int h = 0;
    for(int child : adj[s])
        h = max(h, dfs(child)+1);
    return dp[s] = h;
}

int32_t main()
{
	int n, m, u, v;
	cin >> n >> m;
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < m; i++)
	{
	    cin >> u >> v;
	    adj[u].push_back(v);
	}
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
	    res = max(res, dfs(i));
	}
	cout << res << "\n";
  	return 0;
}