#include <iostream>
#include <cstring>

using namespace std;

#define mod (int)1e9+7

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int dp[(int)1e6+1];

int solve(int *a, int n, int k) {
    if(k == 0)
        return 1;
    if(dp[k] != -1)
        return dp[k];
    int res = 0;
    for(int i = 0; i < n; i++)
        if(a[i] <= k)
            res += solve(a, n, k-a[i]), res %= mod;
    return dp[k] = res;
}

int32_t main() {
    tool();
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int& val: a)
        cin >> val;
    memset(dp, -1, sizeof(dp));
    cout << solve(a, n, k);
    return 0;
}

/*
int solve(int *a, int n, int k) {
    int dp[k+1] = {0};
    dp[0] = 1;
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++)
            if(i-a[j] >= 0)
                dp[i] += dp[i-a[j]];
    }
    return dp[k];
}
*/