// we have given n node, with some node infected by certain diseases.
// also we have certain number of edges (u -> v)
// if any of node is infected then connection also infected
// we have to find how many nod eis infected ast last.

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

struct Graph
{
    int n;
    vector<int> *adj;
    Graph(int n)
    {
        this->n = n;
        adj = new vector<int>[n];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(vector<bool> &);
    void dfs(vector<bool> &, vector<bool> &, int);
};

int32_t main()
{
    tool();
    int n, m, k, l, x, y;
    cin >> n;
    Graph G(n);
    vector<bool> ans(n, false);
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> x, ans[x] = true;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        G.addEdge(x, y);
    }
    G.dfs(ans);
    cin >> l;
    for(int i = 0; i < l; i++)
    {
        cin >> x;
        cout << (ans[x] ? "P\n" : "NP\n");
    }
    return 0;
}

void Graph::dfs(vector<bool> &ans)
{
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
        if (!vis[i] && ans[i])
        {
            dfs(ans, vis, i);
        }
}

void Graph::dfs(vector<bool> &ans, vector<bool> &vis, int s)
{
    vis[s] = true;
    for (int child : adj[s])
        if (!vis[child] && ans[s])
        {
            ans[child] = ans[s];
            dfs(ans, vis, child);
        }
}