// in this problem a teacher have given some problem :
// 5 4
// 1 2
// 2 3
// 1 3
// 4 5
// 5 shows total number of students 
// 4 shows total number of pairs
// now teacher hase to decide how many ways he can choose leaders from each groups ??

// This is basic problem of Disjoint set Union
// we have to basically count the number of elements in each subsets

#include <iostream>
#include <vector>
#include <cmath>

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
    return Find(parent, parent[n]);
}

int Find_path_compression(vector<int>& parent, int n) {
    if(parent[n] < 0) 
        return n;
    return parent[n] = Find_path_compression(parent, parent[n]);
}

void Union(vector<int>& parent, int a, int b) {
    a = Find_path_compression(parent, a);
    b = Find_path_compression(parent, b);
    if(a == b)
        return;
    else {
        // add count of both subsets in single set & make on of them as common parent
        parent[a] += parent[b];
        parent[b] = a;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1, -1);
    while(m--) {
        int x, y;
        cin >> x >> y;
        Union(parent, x, y);
    }
    int ans = 1;
    for(int& val: parent) {
        if(val < 0) {
            ans *= abs(val);
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

