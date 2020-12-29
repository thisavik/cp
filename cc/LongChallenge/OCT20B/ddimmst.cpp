#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

struct edge
{
    int u, wt;
};

struct comp
{
    bool operator()(edge &e1, edge &e2)
    {
        return e1.wt < e2.wt;
    }
};

const int mxN = 2*1e6+1;
int n;
vector<edge> adj[mxN];
vector<bool> mst(mxN);
vector<int> key(mxN);

int maxSpanTree()
{
    fill(key.begin(), key.end(), -1e9);
    fill(mst.begin(), mst.end(), false);
    priority_queue<edge, vector<edge>, comp> pq;
    pq.push({0, 0});
    key[0] = 0;
    while(!pq.empty())
    {
        auto e = pq.top(); pq.pop();
        mst[e.u] = true;
        for(edge child: adj[e.u])
        {
            if(!mst[child.u] && key[child.u] < child.wt)
            {
                key[child.u] = child.wt;
                pq.push(child);
            }
        }
    }
    int cost = 0;
    rep(i, n)
        cost += key[i];
    return cost;
}

void printG()
{
    rep(i, n)
    {
        cout << i << " -> ";
        for(edge e: adj[i])
            cout << "[" << e.u << ", " << e.wt << "], ";
        cout << "\n";
    }
    cout << "\n";
}

int32_t main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while(t--)
    {
        int d;   // n <= 2*1e5 // d <= 5
        cin >> n >> d;
        vector<vector<int>> x(n, vector<int>(d, 0));
        rep(i, n)
        {
            rep(j, d)
            {
                cin >> x[i][j];  // x <= 1e5
            }
        }
        rep(i, n)
        {
            range(j, i+1, n-1)
            {
                int cost = 0;
                rep(k, d)
                    cost += abs(x[i][k]-x[j][k]);
                adj[i].push_back({j, cost}), adj[j].push_back({i, cost});
            }
        }
        // printG();
        cout << maxSpanTree();
    }
    return 0;
}