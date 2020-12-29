#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct unDirectedGraph
{
    int v, e;
    vector<vector<int>> adj;
    unDirectedGraph(int v, int e)
    {
        this->v = v;
        this->e = e;
        for (int i = 0; i < v; i++)
            adj.push_back(vector<int>());
    }

    // u -> v && v -> u
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isCycleDFS(int, bool[], int);
    bool isCycleDFS();
    bool isCycleBFS(int, bool[], int[]);
    bool isCycleBFS();
};

bool unDirectedGraph::isCycleDFS(int s, bool vis[], int parent)
{
    vis[s] = true;
    for (int i : adj[s])
    {
        if (!vis[i])
            return isCycleDFS(i, vis, s);
        else if (i != parent)
            return true;
    }
    return false;
}

bool unDirectedGraph::isCycleDFS()
{
    bool vis[v] = {false};
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            if (isCycleDFS(i, vis, -1))
                return true;
    }
    return false;
}

bool unDirectedGraph::isCycleBFS(int s, bool vis[], int par[])
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    par[s] = -1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i : adj[cur])
        {
            if (!vis[i])
                q.push(i), vis[i] = true, par[i] = cur;
            else if (par[i] != cur && par[i] != -1)
            {
                return true;
            }
        }
    }
    return false;
}

bool unDirectedGraph::isCycleBFS()
{
    bool vis[v] = {false};
    int par[v];
    for (int i = 0; i < v; i++)
        if (!vis[i] && isCycleBFS(i, vis, par))
            return true;
    return false;
}

int32_t main()
{
    tool();
    int v, e;
    cin >> v >> e;

    unDirectedGraph G(v, e);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    cout << G.adj.size() << "\n";
    for (int i = 0; i < G.adj.size(); i++)
    {
        cout << i << " ";
        for (int j = 0; j < G.adj[i].size(); j++)
            cout << G.adj[i][j] << " ";
        cout << "\n";
    }

    cout << G.isCycleDFS() << "\n";
    cout << G.isCycleBFS() << "\n";
    return 0;
}