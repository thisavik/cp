#include <iostream>
#include <cstring>
#include <vector>

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

int dp[(int)1e6+1][101];

int solve(int *a, int n, int k, int i) {
    if(k == 0 && i >= 0)
        return 1;
    if(k < 0 || i < 0)
        return 0;
    if(dp[k][i] != -1)
        return dp[k][i];
    int op1 = solve(a, n, k-a[i], i);
    int op2 = solve(a, n, k, i-1);
    return dp[k][i] = op1 + op2;
}

int32_t main() {
    tool();
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int& val: a)
        cin >> val;
    memset(dp, -1, sizeof(dp));
    cout << solve(a, n, k, n-1);
    return 0;
}

/*
int solve(int *a, int n, int k) {
    int dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j == 0) 
                dp[i][j] = 1;
            else {
                // choose i-1th element 
                int op1 = (a[i-1] > j ? 0 : dp[i][j-a[i-1]]);
                // skip i-1th element
                int op2 = (i == 1 ? 0 : dp[i-1][j]);
                dp[i][j] = op1 + op2;
            }
        }
    }
    return dp[n][k];
}
*/