#include <iostream>
#include <cstring>

using namespace std;

bool isInterleave(string &s1, string &s2, string &s3)
{
    int n = s1.size();
    int m = s2.size();
    bool dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 && j == 0)
            {
                // base case 
                dp[i][j] = true;
            }
            else if(j == 0)
            {
                // base case
                if(s1[i-1] == s3[i-1])
                    dp[i][j] = dp[i-1][j];
            }
            else if(i == 0)
            {
                // base case
                if(s2[j-1] == s3[j-1])
                    dp[i][j] = dp[i][j-1];
            }
            else 
            {
                if(s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                else if(s1[i-1] == s3[i+j-1])
                    dp[i][j] = dp[i-1][j];
                else if(s2[j-1] == s3[i+j-1])
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}

int32_t main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << isInterleave(s1, s2, s3);
}

// if no common character
bool helper(string &s1, string &s2, string &s3) {
    if(s1.size()+s2.size() != s3.size())
        return false;
    int i = 0, j = 0, k = 0;
    while(k < s3.size()) {
        int ans = 0;
        if(i < s1.size() && s1[i] == s3[k])
            ans = 1, i++, k++;
        else if(j < s2.size() && s2[j] == s3[k])
            ans = 1, j++, k++;
        if(!ans)
            return false;
    }
    return true;
}

int helper(string &s1, string &s2, string &s3, int i, int j, int k)
{
    if(i == s1.size() && j == s2.size())
        return true;

    if(i < s1.size() && s1[i] == s3[k] && j < s2.size() && s2[j] == s3[k])
        return helper(s1, s2, s3, i+1, j, k+1) | helper(s1, s2, s3, i, j+1, k+1);

    if(i < s1.size() && s1[i] == s3[k])
        return helper(s1, s2, s3, i+1, j, k+1);
    
    if(j < s2.size() && s2[j] == s3[k])
        return helper(s1, s2, s3, i, j+1, k+1);
    return false;
}