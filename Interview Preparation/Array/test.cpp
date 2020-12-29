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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& val: a)
        cin >> val;
    // 1 3 4 2 5 7 6 10 , consider this test case
    // find the index of last element from the left 
    // which is smaller than last seen max
    int e = -1, mx = INT32_MIN;
    for(int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if(mx > a[i])
            e = i;
    }

    // find the index of last element from the right 
    // which is greater than the last seen min
    int b = - 1, mn = INT32_MAX;
    for(int i = n-1; i >= 0; i--) {
        mn = min(mn, a[i]);
        if(mn < a[i])
            b = i;
    }

    cout << (e-b > 0 ? e-b+1 : 0) << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}