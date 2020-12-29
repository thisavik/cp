#include <iostream>
#include <cstring>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main()
{
    tool();
    int n, k;
    cin >> n >> k;
    int h[n];
    for(int& val : h)
        cin >> val;
    int s[n];
    for(int& val : s)
        cin >> val;
    int dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= h[i-1])
                dp[i][j] = max(dp[i][j], s[i-1] + dp[i-1][j-h[i-1]]);
        }
    }
    cout << dp[n][k];
    return 0;
}