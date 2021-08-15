// dijkstra's algorithm in case of adjacency list
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)

void tool()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("C:/Users/thisa/OneDrive/Documents/cp/input.txt", "r", stdin);
  freopen("C:/Users/thisa/OneDrive/Documents/cp/output.txt", "w", stdout);
  freopen("C:/Users/thisa/OneDrive/Documents/cp/error.txt", "w", stderr);
#endif
}

struct T
{
    int u, wt;
};

struct comp
{
    bool operator()(T &t1, T &t2)
    {
        return t1.wt > t2.wt;
    }
};

vector<T> adj[101];
vector<int> dis(101);



void dijkstra()
{
    fill(dis.begin(), dis.end(), 1e9);
    priority_queue<T, vector<T>, comp> pq;
    // insert source node with weight
    pq.push({0, 0});
    dis[0] = 0;
    while(!pq.empty())
    {
        auto t = pq.top(); pq.pop();
        for(auto child : adj[t.u])
        {
            if(dis[child.u] > dis[t.u]+child.wt)
            {
                dis[child.u] = dis[t.u]+child.wt;
                pq.push({child.u, dis[child.u]});
            }
        }
    }
}

int32_t main()
{
    tool();
    int n, e, u, v, wt;
    cin >> n >> e;
    rep(i, e)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    dijkstra();
    rep(i, n)
        cout << i << " -> " << dis[i] << "\n";
    return 0;
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
7 8 7
7 6 1
2 8 2
2 3 7
2 5 4
8 6 6 
6 5 2
3 5 14
3 4 9
5 4 10
*/