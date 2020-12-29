// Concept is if a graph have 2 as chromatic number then it is Bipartite Graph.

#include <iostream>
#include <vector>
#include <algorithm>
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

struct Graph {
    int N, V;
    vector<int> *adj;
    Graph(int n, int v) {
        N = n, V = v;
        adj = new vector<int>[N+1];
    }
    void addEdge(int, int);
    bool isBipartite();
    bool isBipartite(int, vector<int>&);
    void print();
};

void solve() {
    int n, e;
    cin >> n >> e;
    Graph G(n, e);
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    G.print();
    cout << boolalpha << G.isBipartite() << "\n";
}

int main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::isBipartite(int s, vector<int>& col) {

    col[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i: adj[cur])
            if(col[i] == col[cur])
                return false;
            else if(col[i] == -1){
                col[i] = (col[cur] == 0 ? 1 : 0);
                q.push(i);
            }
    }
    return true;
}

bool Graph::isBipartite() {
    vector<int> col(N+1, -1); 
    for(int i = 1; i <= N; i++) 
        if(col[i] == -1 ) {
            bool flag = isBipartite(i, col);
            if(!flag)
                return false;
        }
    return true;
}

void Graph::print() {
    for(int i = 1; i <= N; i++) {
        cout << i << " ";
        for(int j : adj[i])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}