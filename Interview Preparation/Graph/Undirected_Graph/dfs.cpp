#include <iostream>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct DirectedGraph {
    int v, e;
    vector<vector<int>> adj;
    DirectedGraph(int v, int e) {
        this->v = v;
        this->e = e;
        for(int i = 0; i < v; i++)
            adj.push_back(vector<int>());
    }

    // u -> v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void DFS(int, bool[]);
    void DFSDis();
};


void DirectedGraph::DFS(int s, bool vis[]) {
    vis[s] = true;
    cout << s << " ";
    for(int i : adj[s]) {
        if(!vis[i])
            DFS(i, vis);
    }
}

void DirectedGraph::DFSDis() {
    bool vis[v] = {false};
    for(int i = 0; i < v; i++)
        if(!vis[i]) {
            DFS(i, vis); 
            cout << "\n";
        }
}

int32_t main() {
    tool();
    int v, e;
    cin >> v >> e;

    DirectedGraph G(v, e);

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    cout << G.adj.size() << "\n";
    for(int i = 0; i < G.adj.size(); i++) {
        cout << i << " ";
        for(int j = 0; j < G.adj[i].size(); j++)
            cout << G.adj[i][j] << " ";
        cout << "\n";
    }
    G.DFSDis();
    bool vis[G.v] = {false};
    G.DFS(0, vis);
    return 0;
}