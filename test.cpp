#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

const int INF = 1e9 + 7;

int dp[101][101][101];

int solve(int i, int k, int box, vector<int> prices)
{
    if (k == 0 && box >= 0)
        return 0;
    if (i < 0 || k < 0 || box <= 0)
        return INF;

    if(dp[i][k][box] != -1)
        return dp[i][k][box];
    int op1 = (prices[i] < 0 ? INF : prices[i] + solve(i, k - (i + 1), box - 1, prices));
    int op2 = solve(i - 1, k, box, prices);

    return dp[i][k][box] = min(op1, op2);
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof dp);
        int n, k;
        cin >> n >> k;
        vector<int> prices(k);
        rep(i, k)
                cin >>
            prices[i];
        int ans = solve(k - 1, k, n, prices);
        cout << (ans == INF ? -1 : ans) << "\n";
    }
}