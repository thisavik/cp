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

int LCS(string s1, string s2, string s3)
{
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size(), i, j, k;
    int dp[n1+1][n2+1][n3+1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            for(int k = 1; k <= n3; k++)
            {
                dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
            }
        }
    }
    return dp[n1][n2][n3];
}

void solve() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if(n1 == 0 || n2 == 0 || n3 == 0)
    {
        cout << 0 << "\n";
        return;
    }
    cout << LCS(s1, s2, s3) << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}