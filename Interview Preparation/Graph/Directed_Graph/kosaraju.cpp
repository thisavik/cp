#include <bits/stdc++.h>

using namespace std;

struct Graph
{
    // contain graph
    map<int, vector<int>> adj;
    // contain reverse of graph
    map<int, vector<int>> rAdj;
    // either vertex is visited or not
    set<int> vis;
    // it contains vertices by finish time in reverse order
    stack<int> stk;
    void addEdge(int, int);
    void print();
    // SCC -> Strongly connected component
    void printSCC();
    void reverse();
    void dfs(int s);
    void dfs2(int s);
};

int32_t main()
{
    tool();
    int v, e;
    cin >> v >> e;

    Graph G;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    G.printSCC();
    return 0;
}

void Graph::printSCC()
{
    vis.clear();
    for (auto i = adj.begin(); i != adj.end(); i++)
    {
        if (vis.find(i->first) == vis.end())
        {
            dfs(i->first);
        }
    }
    vis.clear();
    reverse();

    while (!stk.empty())
    {
        int cur = stk.top();
        stk.pop();
        if (vis.find(cur) == vis.end())
        {
            dfs2(cur);
            cout << "\n";
        }
    }
}

void Graph::dfs2(int s)
{
    cout << s << " ";
    vis.insert(s);
    for (int i : rAdj[s])
        if (vis.find(i) == vis.end())
            dfs2(i);
}

void Graph::reverse()
{
    rAdj.clear();
    for (auto i = adj.begin(); i != adj.end(); i++)
    {
        for (int j : i->second)
            rAdj[j].push_back(i->first);
    }
}

void Graph::dfs(int s)
{
    vis.insert(s);
    for (int i : adj[s])
        if (vis.find(i) == vis.end())
            dfs(i);
    stk.push(s);
}

void Graph::print()
{
    for (auto i = adj.begin(); i != adj.end(); i++)
    {
        cout << i->first << " ";
        for (int j : i->second)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

void Graph::addEdge(int u, int v)
{
    // u -> v
    adj[u].push_back(v);
}
