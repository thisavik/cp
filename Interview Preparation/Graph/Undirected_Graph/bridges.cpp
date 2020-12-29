#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct Graph{
    int N, E;
    map<int, vector<int>> adj;
    // disc store discovery time for each node
    // low store discovery time of lowest ancestor which is not its parent
    map<int, int> disc, low;
    set<int> vis;
    int timer;
    Graph(int n, int e): N(n), E(e) {}
    void addEdge(int, int);
    void print();
    vector<pair<int, int>> findBridge();
    void dfs(int, int, vector<pair<int, int>>&);
};

int32_t main() {
    tool();
    int n, e;
    cin >> n >> e;
    Graph G(n, e);
    while(e--) {
        int x, y; cin >> x >> y;
        G.addEdge(x, y);
    }
    G.print();
    vector<pair<int, int>> ans = G.findBridge();
    for(auto p: ans)
        cout << p.first << "->" << p.second << " is bridge\n";
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<pair<int, int>> Graph::findBridge() {
    vector<pair<int, int>> ans;
    timer = 0;
    for(auto i = adj.begin(); i != adj.end(); i++)
        if(vis.find(i->first) == vis.end())
            dfs(i->first, -1, ans);
    return ans;
}

void Graph::dfs(int s, int par, vector<pair<int, int>>& ans) {
    vis.insert(s);
    disc[s] = low[s] = timer++;
    for(int i: adj[s]) {
        if(i == par)
            continue;
        if(vis.find(i) != vis.end()) {
            // edge type node -> ancestor back edge
            low[s] = min(low[s], disc[i]);
        } else {
            // edge type node -> descendent forward edge
            dfs(i, s, ans);
            low[s] = min(low[s], low[i]);
            if(low[i] > disc[s]) {
                ans.push_back({s ,i});
            } 
        }
    }
}

void Graph::print() {
    for(auto i = adj.begin(); i != adj.end(); i++) {
        cout << i->first << " ";
        for(int j: i->second)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}