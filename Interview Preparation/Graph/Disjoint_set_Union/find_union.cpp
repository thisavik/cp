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

int Find(vector<int>& par, int n) {
    if(par[n] < 0)
        return n;
    return par[n];
}

void Union(vector<int>& par, int a, int b) {
    par[b] = a;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> par(n+1);

    for(int i=1; i<=n; i++)
        par[i] = -1;

    while(m--) {
        int x, y;
        cin >> x >> y;
        x = Find(par, x);
        y = Find(par, y);
        if(x != y)
            Union(par, x, y);
    }

    for(int& val: par)
        cout << val << " ";
    cout << " \n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}