#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<string> in(n);
    rep(i, n)
    {
        cin >> in[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    rep(i, n)
    {
        rep(j, m)
        {
            if (in[i][j] == '.')
            {
                if (i - 1 >= 0)
                    dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}