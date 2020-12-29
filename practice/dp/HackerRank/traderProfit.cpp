#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int dp[31][2][11];

int maxProfit(int i, bool own, int k, int *a, int n) {
    if(i == n+1 || k == 0)
        return 0;
    if(dp[i][own][k] != -1)
        return dp[i][own][k];
    // we already have stock in hand
    if(own) {
        // sell it
        int op1 = a[i-1] + maxProfit(i+1, 0, k-1, a, n);
        // don't sell it
        int op2 = maxProfit(i+1, 1, k, a, n);
        return dp[i][own][k] = max(op1, op2);
    } 
    // we don't have stock in hand
    else {
        // either purchase it
        int op1 = -a[i-1] + maxProfit(i+1, 1, k, a, n);
        // not purchase it
        int op2 = maxProfit(i+1, 0, k, a, n);
        return dp[i][own][k] = max(op1, op2);
    }
}

int maxProfit(int *a, int n, int k) {
    memset(dp, -1, sizeof dp);
    // initially we have nothing in stock
    return maxProfit(1, 0, k, a, n);
}

void solve() {
    int n, k;
    cin >> k >> n;
    int a[n];
    for(int& val: a)
        cin >> val;
    cout << maxProfit(a, n, k) << "\n";
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    while(n--)
        solve();
    return 0;
}