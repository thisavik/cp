#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

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
    vector<int> a(n+1), v;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++) {
        int x = a[i];
        int cnt = 1;
        while(x != i) {
            x = a[x];
            cnt++;
        }
        v.push_back(cnt);
    }
    int ans = 1;
    for(int i=0; i<v.size(); i++) {
        ans = (ans*v[i])/__gcd(ans, v[i]);
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