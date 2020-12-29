#include <bits/stdc++.h>
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

int main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int value[n][3];
        for (int i = 0; i < n; i++)
            cin >> value[i][0] >> value[i][1] >> value[i][2];
        int dp[n + 1][3];
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + value[i - 1][0];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + value[i - 1][1];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + value[i - 1][2];
        }
        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
    }
    return 0;
}
/*
2
3
10 40 70
20 50 80
30 60 90
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
*/