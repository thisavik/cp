#include <iostream>
#include <cstring>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int LCS(string s1, string s2)
{
    int n = s1.size(), m = s2.size(), maxLen = 0;
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    return maxLen;
}

int32_t main()
{
    string s1 = "ABCDGH", s2 = "ACDGHR";
    cout << LCS(s1, s2) << "\n";
    return 0;
}