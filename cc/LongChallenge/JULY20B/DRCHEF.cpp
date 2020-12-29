#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

#define int long long
#define FORI(i, a, n) for(int i=a; i<n; i++)

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for(int& val: a)
        cin >> val;

    sort(a.begin(), a.end());
    
    int ans = 0, l = 0;

    FORI(i, 0, n) {
        if(x >= a[i]) {
            x = max(a[i]*2, x);
            ans++;
            l = i + 1;
        } else {
            break;
        }
    }
    // cout << ans << " " << l << "\n";
    FORI(i, l, n) {
        while(x < a[i]) {
            ans++;
            x *= 2;
        }
        ans++;
        x = 2*a[i];
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