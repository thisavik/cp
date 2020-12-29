// only for Directed Acyclic Graph (DAG)

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    void topologicalSortBFS();
    void DFS(int, bool[], stack<int>&);
    void topologicalSortDFS();
};

void DirectedGraph::topologicalSortBFS() {
    vector<int> inDeg(v, 0); 
    for(int i = 0; i < v; i++) {
        for(int j : adj[i])
            inDeg[j]++;
    }
    queue<int> q;
    for(int i = 0; i < v; i++) 
        if(inDeg[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i : adj[cur]) {
            inDeg[i]--;
            if(inDeg[i] == 0)
                q.push(i);
        }
    }
    cout << "\n";
}

void DirectedGraph::DFS(int s, bool vis[], stack<int>& stk) {
    vis[s]= true;
    for(int i : adj[s])
        if(!vis[i])
            DFS(i, vis, stk);
    stk.push(s);
}

void DirectedGraph::topologicalSortDFS() {
    stack<int> stk;
    bool vis[v] = {false};
    for(int  i = 0; i < v; i++)
        if(!vis[i])
            DFS(i, vis, stk);
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";
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
    G.topologicalSortBFS();
    G.topologicalSortDFS();
    return 0;
}