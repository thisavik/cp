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

int solve(int n, int k) {
    int dp[n+1][k+1];
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= k; i++)
        dp[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j == 1 || i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = j*dp[i-1][k] + dp[i-1][j-1];
        }
    }
    return dp[n][k];
}

int32_t main() {
    tool();
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
}