// working on adjacency list of tree
// finding lowest common ancestor

#include <iostream>
#include <vector>

using namespace std;

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

const int N = (int)1e3+1;
// for creating graph
vector<int> adj[N];
int level[N], parent[N];

void dfs(int node, int lvl, int par) {
    level[node] = lvl;
    parent[node] = par;
    for(int child : adj[node])
        // ensure we don't make recursive call to parent
        if(child != par)
            dfs(child, lvl+1, node);
}

void init(int n) {
    dfs(1, 0, -1);
}

int LCA(int a, int b) {
    if(level[b] < level[a]) swap(b, a);

    int d = level[b] - level[a];

    // lifting of 1 node up each time
    while(d--)
        b = parent[b];
    
    // if a and b lies on same path
    if(a == b)
        return a;

    // lifting of 1 node up each time
    while(parent[a] != parent[b])
        a = parent[a], b = parent[b];
    return parent[a];
}

int32_t main() {
    // tool();
    int n, a, b;
    cin >> n;
    // n node -> n-1 edeges in case of tree
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}