#include <iostream>
#include <cstring>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

pair<int, int> longestPalSubstr(string s);

pair<int, int> LPS(string s)
{
    int n = s.size(), maxLen = 1, start = 0;
    bool dp[n][n];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            maxLen = 2;
            start = i;
        }

    for (int k = 3; k <= n; k++)
    {
        for (int j = k - 1, i = 0; j < n; j++, i++)
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                if (maxLen < k)
                {
                    maxLen = k;
                    start = i;
                }
            }
    }
    return {start, maxLen};
}

void solve()
{
    string s;
    cin >> s;
    auto p = LPS(s);
    cout << s.substr(p.first, p.second) << "\n";
    auto q = longestPalSubstr(s);
    cout << s.substr(q.first, q.second) << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

pair<int, int> longestPalSubstr(string str)
{
    int maxLen = 1, start = 0, len = str.size();
    int s, e;
    for(int i = 1; i < len; i++)
    {
        // even length
        s = i-1, e = i;
        while(s >= 0 && e < len && str[s] == str[e])
        {
            if(maxLen < e-s+1)
                start = s, maxLen = e-s+1;
            s--, e++;
        }

        // odd length
        s = i-1, e = i+1;
        while(s >= 0 && e < len && str[s] == str[e])
        {
            if(maxLen < e-s+1)
                start = s, maxLen = e-s+1;
            s--, e++;
        }
    }
    return {start, maxLen};
}