#include <bits/stdc++.h>

using namespace std;

struct Tree
{
    int size, timer;
    vector<vector<int>> adj;
    vector<int> par;
    vector<int> enterTime;
    vector<int> exitTime;
    vector<int> eulerTree;
    Tree() {}
    Tree(int &size)
    {
        this->size = size;
        timer = 0;
        adj.resize(size + 1);
        par.resize(size + 1, -1);
        enterTime.resize(size + 1);
        exitTime.resize(size + 1);
        eulerTree.resize(2 * size);
    }
    void buildAdjWithEdges(vector<vector<int>> &edges)
    {
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
    }
    void buildParWithEdges(vector<vector<int>> &edges)
    {
        for (auto &edge : edges)
        {
            par[edge[1]] = edge[0];
        }
    }
    void addEdge(int &u, int &v)
    {
        adj[u].push_back(v);
    }
    void buildEulerTree(int src, int par)
    {
        enterTime[src] = timer;
        eulerTree[timer] = src;
        timer++;
        for (auto &child : adj[src])
        {
            buildEulerTree(child, src);
        }
        exitTime[src] = timer;
        eulerTree[timer] = src;
        timer++;
    }
    void printTree()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << i << " : ";
            for (auto &child : adj[i])
            {
                cout << child << " ";
            }
            cout << "\n";
        }
    }
    void printEulerTree()
    {
        for (int i = 0; i < 2 * size; i++)
            cout << eulerTree[i] << " ";
        cout << "\n";
    }
    void printParent()
    {
        for (int i = 1; i <= size; i++)
            cout << i << " : " << par[i] << "\n";
    }
};

int32_t main()
{
    int n, x, y;
    cin >> n;
    vector<vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        edges[i] = {x, y};
    }
    Tree t(n);
    t.buildParWithEdges(edges);
    t.printParent();
    t.buildAdjWithEdges(edges);
    t.printTree();
    return 0;
}