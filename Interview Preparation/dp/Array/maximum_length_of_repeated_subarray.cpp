#include <iostream>
#include <cstring>
#include <vector>

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

int solve(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    if(n == 0 || m == 0)
        return 0;
    int maxLen = 0;
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(A[i-1] == B[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    return maxLen;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for(int& val: A)
        cin >> val;
    for(int& val: B)
        cin >> val;        
    cout << solve(A, B) << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}