/*
we have given a tree with n node rooted at 1.
Also, a value is associated with each node.
we have to find ancestor of each node such that value of the node with that ancestor 
is coprime with each other. if that ancestor doesn't exist that ans for that node is -1.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct  Tree {
    int n;
    vector<int> *a, wgt;
    vector<bool> vis;
    vector<int> par;
    int timer;
    Tree(int n) {
        this->n = n;
        a = new vector<int>[n+1];
        wgt.resize(n+1, 0);
        vis.resize(n+1, false);
        par.resize(n+1, 0);
    }

    void addEdge(int u, int v) {
        a[u].push_back(v);
        a[v].push_back(u);
    }
    void printGraph();
    void printNode();
    void init();
    void dfs(int, int);
    void solve(int, vector<int>&);
};


void solve() {
    int n;
    cin >> n;
    Tree t(n);
    for(int i = 1; i <= n; i++) {
        cin >> t.wgt[i];
    }
    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        t.addEdge(u, v);
    }
    vector<int> ans(n+1, 0);
    t.printGraph();
    t.init();
    t.printNode();
    for(int i = 1; i <= n; i++)
        t.solve(i, ans);
    cout << "\n";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

void Tree::printGraph() {
    for(int i = 1; i <= n; i++) {
        cout << i << " ";
        for(int j : a[i])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

// for creating parent array
void Tree::init() {
    dfs(1, -1);
}

void Tree::dfs(int s, int p) {
    par[s] = p;
    for(int i: a[s])
        if(i != p)
            dfs(i, s);
}

void Tree::printNode() {
    for(int i = 1; i <= n; i++)
        cout << i << " -> " << par[i] << ", " << wgt[i] << "\n";
    cout << "\n";
}

void Tree::solve(int s, vector<int>& ans) {
    int k = wgt[s], ancestor = par[s];
    while(ancestor != -1) {
        if(__gcd(k, wgt[par[s]]) == 1) {
            ans[s] = ancestor;
            return;
        } else
            ancestor = par[ancestor];
    }
    ans[s] = -1;
}