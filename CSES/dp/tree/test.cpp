#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
}

struct Tree {
    int n;
    vector<int> *a;
    bool *vis;
    Tree(int n) {
        this->n = n;
        a = new vector<int>[n+1];
        vis = new bool[n+1];
    }
    void addEdge(int u, int v) {
        a[u].push_back(v);
        a[v].push_back(u);
    }
    void dfs(vector<int>&);
    void dfs(int, int, vector<int>&);
};

int32_t main() {
    tool();
    int n;
    cin >> n;
    Tree t(n);
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        t.addEdge(i, u);
    }
    vector<int> ans(n+1, 0);
    t.dfs(ans);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}

void Tree::dfs(vector<int>& ans) {
    memset(vis, false, sizeof(vis));
    dfs(1, 0, ans);
}

void Tree::dfs(int s, int par, vector<int>& ans) {
    vis[s] = true;
    int subords = 0;
    for(int i: a[s]) {
        if(!vis[i]) {
            dfs(i, s, ans);
            subords += (1 + ans[i]);
        }
    }
    ans[s] = subords;
}