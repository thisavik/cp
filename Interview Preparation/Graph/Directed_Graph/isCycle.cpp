#include <iostream>
#include <vector>
#include <queue>

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
    bool isCycleDFS(int, bool[], bool[]);
    bool isCycleDFS();
    bool isCycleBFS();
};

// using concept of topological sort, as queue become empty before iterating all vertex
// in case of cyclic graph

bool DirectedGraph::isCycleBFS() {

    vector<int> inDeg(v, 0);
    for(int i = 0; i < v; i++)
        for(int j : adj[i])
            inDeg[j]++;
    queue<int> q;
    
    for(int i = 0; i < v; i++)
        if(inDeg[i] == 0)
            q.push(i);
    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        for(int i : adj[cur]) {
            inDeg[i]--;
            if(inDeg[i] == 0)
                q.push(i);
        }
    }
    return cnt != v;
}

bool DirectedGraph::isCycleDFS(int s, bool vis[], bool recStk[]) {
    vis[s] = true;
    recStk[s] = true;
    for(int i : adj[s]) {
        if(!vis[i])
            return isCycleDFS(i, vis, recStk);
        else
            if(recStk[i]) {
                return true;
            }
    }
    recStk[s] = false;
    return false;
}

bool DirectedGraph::isCycleDFS() {
    bool vis[v] = {false};
    bool recStk[v] = {false};
    for(int i = 0; i < v; i++) {
        if(!vis[i])
            if(isCycleDFS(i, vis, recStk))
                return true;
    }
    return false;
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

    cout << G.isCycleDFS() << "\n";
    cout << G.isCycleBFS() << "\n";
    return 0;
}
