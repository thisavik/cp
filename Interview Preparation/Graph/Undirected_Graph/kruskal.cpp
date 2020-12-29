// Minimum Spanning tree(MST) using Kruskal's Algorithm
// using Disjoint Set Union (DSU) data structure

#include <iostream>
#include <algorithm>

using namespace std;

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct edge {
    int a, b, w;
};

edge ar[(int)1e5];
int parent[(int)1e4+1];

int Find(int a) {
    if(parent[a] == -1)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    parent[a] = b;
}

int32_t main() {
    tool();
    int n, e, a, b, w, sum = 0;
    cin >> n >> e;

    for(int i = 1; i <= n; i++)
        parent[i] = -1;

    for(int i = 0; i < e; i++)
        cin >> ar[i].a >> ar[i].b >> ar[i].w;
    
    sort(ar, ar+e, [](edge& a, edge& b) {
        return a.w < b.w;
    });

    for(int i = 0; i < e; i++) {
        a = Find(ar[i].a), b = Find(ar[i].b);
        if(a != b)
            Union(a, b), sum += ar[i].w;
    }
    cout << sum << "\n";
    return 0;
}