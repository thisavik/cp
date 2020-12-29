// Minimum spanning tree(MST) using Prims algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct unDirectedGraph {
    int v, e;
    vector<vector<int>> adj;
    map<pair<int, int>, int> wgt;
    unDirectedGraph(int v, int e) {
        this->v = v;
        this->e = e;
        for(int i = 0; i < v; i++)
            adj.push_back(vector<int>());
    }

    // u -> v
    void addEdge(int u, int v, int dis) {
        adj[u].push_back(v);
        wgt[{u, v}] = dis;
        adj[v].push_back(u);
        wgt[{v, u}] = dis;
    }
    int primsMST();
};

int unDirectedGraph::primsMST() {
    int key[v], res = 0;
    fill(key, key+v, (int)1e9);
    key[0] = 0;
    bool mSet[v] = {false};
    for(int i = 0; i < v; i++) {
        int u = -1;
        for(int j = 0; j < v; j++) {
            if(!mSet[j] && (u == -1 || key[i] < key[u]))
                u = i;
        }
        mSet[u] = true; 
        res += key[u];
        for(int v : adj[u])
            if(!mSet[v])
                key[v] = min(key[v], wgt[{u, v}]);
    }
    return res;
}

int32_t main() {
    tool();
    int v, e;
    cin >> v >> e;

    unDirectedGraph G(v, e);

    for(int i = 0; i < e; i++) {
        int u, v, dis;
        cin >> u >> v >> dis;
        G.addEdge(u, v, dis);
    }
    cout << G.adj.size() << "\n";
    for(int i = 0; i < G.adj.size(); i++) {
        cout << i << " ";
        for(int j = 0; j < G.adj[i].size(); j++)
            cout << G.adj[i][j] << " ";
        cout << "\n";
    }
    cout << G.primsMST() << "\n";
    return 0;
}