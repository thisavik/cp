#include <iostream>
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

int solve(string s) {
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int k = 0; k < n; k++) {
        for(int j = k, i = 0; j < n; j++, i++)
            if(i == j)
                dp[i][j] = 1;
            else {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    return dp[0][n-1];
}

int32_t main() {
    tool();
    string s;
    cin >> s;
    cout << solve(s);
}