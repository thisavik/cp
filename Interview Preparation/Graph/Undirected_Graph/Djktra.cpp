#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

// adj is pair since we have to store edges weight also (node, weight)
vector<pair<int, int>> adj[(int)1e3+1];

int32_t main() {
    tool();
    int n, e, a, b, w;
    cin >> n >> e;

    // creating graph
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    // we want a data structure which can perform three things efficiently:
    // 1- insert an element into it
    // 2- delete an element from it 
    // 3- finding minimum element from it
    // we will push weight first then node value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n+1, (int)1e9);
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cur_d = pq.top().first;
        pq.pop();

        for(auto edge: adj[cur]) {
            if(cur_d + edge.second < dist[edge.first]) {
                dist[edge.first] = cur_d + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }
    for(int i = 1; i <= n; i++) 
        cout << dist[i] << " ";
    cout << "\n";
    return 0;
}