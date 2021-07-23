#include <bits/stdc++.h>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int helperRec(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if(i == s1.size() || j == s2.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans;
    if(s1[i] == s2[j])
        ans = 1 + helperRec(i+1, j+1, s1, s2, dp);
    else 
        ans = max(helperRec(i+1, j, s1, s2, dp), helperRec(i, j+1, s1, s2, dp));
    return dp[i][j] = ans;
}

int helper(string &s1, string &s2)
{
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    return helperRec(0, 0, s1, s2, dp);
}

pair<string, int> LCS(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    for (int i = n, j = m; i > 0 && j > 0;)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else
            ans += s1[i - 1], i--, j--;
    }
    reverse(ans.begin(), ans.end());
    return {ans, dp[n][m]};
}

int32_t main()
{
    string s1 = "ABCDGH", s2 = "AEDFHR";
    cout << helper(s1, s2);
    return 0;
}