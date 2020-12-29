// prim's algorithm in case of adjacency list
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

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
vector<int> parent(101);
vector<bool> mst(101);
vector<int> key(101);



void primMST()
{
    fill(key.begin(), key.end(), 1e9);
    fill(parent.begin(), parent.end(), -1);
    fill(mst.begin(), mst.end(), false);
    priority_queue<T, vector<T>, comp> pq;
    // insert source node with weight
    pq.push({0, 0});
    key[0] = 0;
    while(!pq.empty())
    {
        int t = pq.top().u; pq.pop();
        mst[t] = true;
        for(auto child : adj[t])
        {
            if(!mst[child.u] && key[child.u] > child.wt)
            {
                key[child.u] = child.wt;
                pq.push({child.u, child.wt});
                parent[child.u] = t;
            }
        }
    }
}

int32_t main()
{
    int n, e, u, v, wt;
    cin >> n >> e;
    rep(i, e)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    primMST();
    int mstCost = 0;
    rep(i, n)
    {
        cout << i << " parent : " << parent[i] << " key : " << key[i] << "\n";
        mstCost += key[i];
    }
    cout << mstCost << "\n";
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