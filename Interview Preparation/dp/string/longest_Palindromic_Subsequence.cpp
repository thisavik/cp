#include <iostream>
#include <cstring>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int helper(int i, int j, string &s)
{
    // if i > j which is impossible then return 0
    if(i > j)
        return 0;
    // one length string is always palindrome
    if(i == j)
        return 1;
    int ans;  
    // if charater at ith and jth match then 2 charater matches
    // after this check for the length of palindrome in between (i+1, j-1)
    if(s[i] == s[j])
        ans = 2 + helper(i+1, j-1, s);
    // if not then check for chracter in between (i, j-1) & (i+1, j)
    else
        ans = max(helper(i, j-1, s), helper(i+1, j, s));
    return ans;
}

int solve(string s)
{
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i+len-1 <= n-1; i++) 
        {
            int j = i+len-1;
            if (i == j)
                dp[i][j] = 1;
            else
            {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int32_t main()
{
    tool();
    string s = "abbbbb";
    // cin >> s;
    // cout << solve(s);
    cout << helper(0, s.size()-1, s);
}