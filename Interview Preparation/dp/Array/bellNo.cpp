#include <iostream>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int Bell(int n) {
    int dp[n+1][n+1];
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][1] = dp[i-1][i-1];
        for(int j = 2; j <= i; j++)
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
    }
    return dp[n][n];
}

void solve() {
    int n;
    cin >> n;
    cout << Bell(n) << "\n"; 
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}