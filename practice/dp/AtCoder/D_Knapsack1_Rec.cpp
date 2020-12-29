#include <bits/stdc++.h>

using namespace std;

#define int long long 

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

int dp[101][(int)1e5+1];

int solve(int *w, int *v, int n, int W)
{
    if(n == 0)
        return 0;
    if(dp[n][W] != -1)
        return dp[n][W];
    int op1, op2;
    op1 = op2 = -1e9;
    // not include
    op1 = solve(w, v, n-1, W);

    // include
    if(W >= w[n-1])
        op2 = v[n-1] + solve(w, v, n-1, W-w[n-1]);
    return dp[n][W] = max(op1, op2);
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
    {
        int n, W;
        cin >> n >> W;
        int w[n], v[n];
        for(int i = 0; i < n; i++)
            cin >> w[i] >> v[i];
        memset(dp, -1, sizeof dp);
        cout << solve(w, v, n, W) << "\n";
    }
    return 0;
}