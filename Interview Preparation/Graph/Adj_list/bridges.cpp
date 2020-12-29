#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)

const int mxN = 1e5+1;
vector<int> adj[mxN];
vector<int> low(mxN);
vector<int> disc(mxN);
vector<bool> vis(mxN);
int n, timer = 0;

void bridges(int src, int par, vector<pair<int, int>> &bridge)
{
    vis[src] = true;
    low[src] = disc[src] = ++timer;
    for(auto u: adj[src])
    {
        if(u == par)
            continue;
        if(vis[u])
            low[src] = min(low[src], disc[u]);
        else
        {
            bridges(u, src, bridge);
            low[src] = min(low[u], low[src]);
            if(low[u] > disc[src])
                bridge.push_back({src, u});
        }
    }
}

vector<pair<int, int>> bridges()
{
    vector<pair<int, int>> bridge;
    fill(low.begin(), low.end(), -1);
    fill(disc.begin(), disc.begin(), -1);
    fill(vis.begin(), vis.end(), false);
    rep(i, n)
        if(!vis[i])
            bridges(i, -1, bridge);
    return bridge;
}

int32_t main()
{
    int e, u, v;
    cin >> n >> e;
    rep(i, e)
        cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    vector<pair<int, int>> bridge = bridges();
    rep(i, bridge.size())
        cout << bridge[i].first << " - " << bridge[i].second << "\n";
}