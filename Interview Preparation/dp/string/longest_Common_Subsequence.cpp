#include <iostream>
#include <cstring>
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

pair<string, int> LCS(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans = "";
    for(int i = n, j = m; i > 0 && j > 0;)
    {
        if(dp[i][j] == dp[i-1][j])
            i--;
        else if(dp[i][j] == dp[i][j-1])
            j--;
        else
            ans += s1[i-1], i--, j--;
    }
    reverse(ans.begin(), ans.end());
    return {ans, dp[n][m]};
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    auto ans = LCS(s1, s2);
    cout << ans.first << " " << ans.second << "\n";
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}