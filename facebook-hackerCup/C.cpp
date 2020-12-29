#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
    vector<pair<int, int>> v(n);
    for(auto& p: v)
        cin >> p.first >> p.second;
    sort(v.begin(), v.end());
    int ans = 0;
    map<int, int> dp;
    for(auto& p: v) {
        int pos = p.first;
        int h = p.second;
        dp[pos+h] = max(dp[pos+h], dp[pos]+h);
        dp[pos] = max(dp[pos] , dp[pos-h]+h);
        ans = max({ans, dp[pos], dp[pos+h]});
        cout << pos << " " << dp[pos] << "\n";
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