#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int t = 1;
    while (t--)
    {
        int n, W, V = 0;
        cin >> n >> W;
        int w[n], v[n];
        for (int i = 0; i < n; i++)
            cin >> w[i] >> v[i], V += v[i];
        int dp[n + 1][V + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                if (j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = 1e9;
                else
                {
                    int op1 = dp[i - 1][j];
                    int op2 = (j >= v[i - 1]) ? (dp[i - 1][j - v[i - 1]] + w[i - 1]) : 1e9;
                    dp[i][j] = min(op1, op2);
                }
            }
        }
        int ans;
        for (ans = V; ans >= 0; ans--)
            if (dp[n][ans] <= W)
                break;
        cout << ans;
    }
    return 0;
}