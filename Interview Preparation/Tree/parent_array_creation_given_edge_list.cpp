#include <iostream>
#include <vector>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

struct Tree
{
    int n;
    vector<int> *adj;
    vector<int> par;
    Tree(int);
    void addEdge(int, int);
    void dfs(int, int);
};

void solve()
{
    int n;
    cin >> n;
    Tree t(n);
    for (int i = 0; i < n - 1; i++) 
    {
        int u, v;
        cin >> u >> v;
        t.addEdge(u, v);
    }
    t.dfs(1, -1);
    for (int i = 1; i <= n; i++)
        cout << i << " -> " << t.par[i] << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

Tree::Tree(int n)
{
    this->n = n;
    adj = new vector<int>[n + 1];
    par.resize(n + 1);
}

void Tree::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Tree::dfs(int s, int p) 
{
    par[s] = p;
    for(int i: adj[s])
        if(i != p)
            dfs(i, s);
}