#include <iostream>
#include <cstring>

using namespace std;

#define mod (int)1e9+7

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int dp[(int)1e6+1];
int solve(int n) {
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    int ans = 0;
    for(int i = 1; i <= 6; i++)
        ans += solve(n-i), ans %= mod;
    return dp[n] = ans;
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    int cnt = 0;
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
}
// 937196411

/*
int solve(int n) {
    int dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 6; j++)
            if(i-j >= 0)
                dp[i] += dp[i-j], dp[i] %= mod;
    }
    return dp[n];
}
*/