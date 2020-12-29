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
        return 0;
    if(dp[k] != -1)
        return dp[k];
    int res = INT32_MAX;
    for(int i = 0; i < n; i++) {
        if(a[i] <= k) {
            int sub_res = solve(a, n, k-a[i]);
            if(sub_res != INT32_MAX && sub_res + 1 < res)
                res = sub_res + 1, res %= mod;
        }
    }
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
    int dp[k+1];
    for(int i = 0; i <= k ; i++)
        dp[i] = (int)1e9;
    dp[0] = 0;
    for(int j = 0; j <= k; j++) {
        for(int i = 0; i < n; i++) 
            if(j-a[i] >= 0)
                dp[j] = min(dp[j], dp[j-a[i]]+1);
    }
    for(int i = 0; i <= k; i++)
        cout << dp[i] << " ";
    cout << "\n";
    return dp[k];
}
*/