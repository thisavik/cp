#include <iostream>
#include <cstring>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main()
{
    tool();
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int &val : a)
        cin >> val;
    int dp[n + 2][m + 2];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (i == 1)
            {
                if (a[i - 1] == 0 || a[i - 1] == x)
                    dp[i][x] = 1;
                else
                    dp[i][x] = 0;
            }
            else
            {
                if (a[i - 1] == 0 || a[i - 1] == x)
                {
                    dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x]) % mod + dp[i - 1][x + 1]) % mod;
                }
                else
                    dp[i][x] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n][i]) % mod;
    cout << ans;
}