#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int& val: a)
        cin >> val;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) 
        dp[i][i] = a[i];
    
    for(int gap = 1; gap < n; gap++) {
        for(int i = 0, j = gap; j < n; j++, i++) {
            int x = dp[i+2][j];
            int y = dp[i+1][j-1];
            int z = dp[i][j-2];
            dp[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << dp[0][n-1] << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}