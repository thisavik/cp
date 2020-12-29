#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

struct DirectedGraph
{
    int v, e;
    vector<vector<int>> adj;
    map<pair<int, int>, int> wgt;
    DirectedGraph(int v, int e)
    {
        this->v = v;
        this->e = e;
        for (int i = 0; i < v; i++)
            adj.push_back(vector<int>());
    }

    // u -> v
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    vector<int> topologicalSortBFS();
    vector<int> shortestPathDAG(int);
};

vector<int> DirectedGraph::topologicalSortBFS()
{
    vector<int> inDeg(v, 0), tSort;
    for (int i = 0; i < v; i++)
        for (int j : adj[i])
            inDeg[j]++;
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (inDeg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        tSort.push_back(cur);
        q.pop();
        for (int i : adj[cur])
        {
            inDeg[i]--;
            if (inDeg[i] == 0)
                q.push(i);
        }
    }
    return tSort;
}

// for DAG graph
vector<int> DirectedGraph::shortestPathDAG(int s)
{
    vector<int> tSort = topologicalSortBFS();

    vector<int> dis(v, INT32_MAX);
    dis[s] = 0;
    for (int i : tSort)
    {
        for (int j : adj[i])
        {
            dis[j] = min(dis[j], dis[i] + wgt[{i, j}]);
        }
    }
    return dis;
}

int32_t main()
{
    tool();
    int v, e;
    cin >> v >> e;

    DirectedGraph G(v, e);

    for (int i = 0; i < e; i++)
    {
        int u, v, dis;
        cin >> u >> v >> dis;
        G.addEdge(u, v);
        G.wgt[{u, v}] = dis;
    }
    for (int i = 0; i < G.adj.size(); i++)
    {
        cout << i << " ";
        for (int j = 0; j < G.adj[i].size(); j++)
            cout << G.adj[i][j] << " ";
        cout << "\n";
    }
    vector<int> dis = G.shortestPathDAG(0);
    for (int i : dis)
        cout << i << " ";
    return 0;
}