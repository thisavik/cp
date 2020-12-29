#include <iostream>
#include <algorithm>

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
    int dp[n+1] = {0};
    dp[1] = 1;
    int i2, i3, i5, n2, n3, n5;
    i2 = i3 = i5 = n2 = n3 = n5 = 1;
    for(int i = 2; i <= n; i++) {
        n2 = dp[i2]*2;
        n3 = dp[i3]*3;
        n5 = dp[i5]*5;
        dp[i] = min({n2, n3, n5});
        if(dp[i] == n2)
            i2++;
        if(dp[i] == n3)
            i3++;
        if(dp[i] == n5)
            i5++;
    }
    cout << dp[n] << "\n"; 
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}