// find the minimum in each disjoint subset 

#include <iostream>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int Find(vector<int>& parent, int n) {
    if(parent[n] < 0)
        return n;
    return parent[n] = Find(parent, parent[n]);
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = Find(parent, a);
    b = Find(parent, b); 

    if(a != b) {
        if(rank[a] < rank[b]) {
            // b would be parent
            parent[b] = max(parent[a], parent[b]);
            parent[a] = b;
            rank[b] += rank[a];
        } else {
            // a would be parent
            parent[a] = max(parent[a], parent[b]);
            parent[b] = a;
            rank[a] += rank[b];
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    // Parent conatin combined information about subset as per requirement
    // Rank contain size of each subset in parent 
    vector<int> parent(n+1), rank(n+1);

    for(int i=1; i<=n; i++)
        parent[i] = -i, rank[i] = 1;

    while(m--) {
        int x, y;
        cin >> x >> y;
        Union(parent, rank, x, y);
    }

    for(int& val: parent)
        cout << val << " ";
    cout << " \n";
    for(int& val: rank)
        cout << val << " ";
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