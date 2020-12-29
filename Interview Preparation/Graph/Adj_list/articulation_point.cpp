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

void articulationPoint(int src, int par, vector<int> &result)
{
    vis[src] = true;
    low[src] = disc[src] = ++timer;
    int children = 0;
    for(auto u: adj[src])
    {
        if(u == par)
            continue;
        if(vis[u])
            low[src] = min(low[src], disc[u]);
        else
        {
            children++;
            articulationPoint(u, src, result);
            low[src] = min(low[u], low[src]);
            if(low[u] >= disc[src] && par != -1)
                result.push_back(src);
        }
    }
    if(children > 1 && par == -1)
        result.push_back(src);
}

vector<int> articulationPoint()
{
    vector<int> result;
    fill(low.begin(), low.end(), -1);
    fill(disc.begin(), disc.begin(), -1);
    fill(vis.begin(), vis.end(), false);
    rep(i, n)
        if(!vis[i])
            articulationPoint(i, -1, result);
    return result;
}

int32_t main()
{
    int e, u, v;
    cin >> n >> e;
    rep(i, e)
        cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    vector<int> result = articulationPoint();
    rep(i, result.size())
        cout << result[i] << "\n";
}