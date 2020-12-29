#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int req, n;
    cin >> req >> n;
    int coins[n];
    for (int &val : coins)
        cin >> val;
    int dp[req + 1];
    fill(dp, dp + req + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= req; i++)
    {
        for (int j = 0; j < n; j++)
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
    if (dp[req] == (int)1e9)
        cout << -1 << "\n";
    else
        cout << dp[req] << "\n";
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