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

// Recursive
bool isSubsetSumRecursive(vector<int> &a, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (sum != 0 && n == 0)
    {
        return false;
    }
    if (a[n - 1] <= sum)
    {
        return isSubsetSumRecursive(a, sum - a[n - 1], n - 1) || isSubsetSumRecursive(a, sum, n - 1);
    }
    else
    {
        return isSubsetSumRecursive(a, sum, n - 1);
    }
}

int dp[1001][1001];

// bottom up code
bool isSubsetSumBottomUp(vector<int> &a, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (sum != 0 && n == 0)
    {
        return false;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (a[n - 1] <= sum)
    {
        return dp[n][sum] = isSubsetSumBottomUp(a, sum - a[n - 1], n - 1) || isSubsetSumBottomUp(a, sum, n - 1);
    }
    else
    {
        return dp[n][sum] = isSubsetSumBottomUp(a, sum, n - 1);
    }
}

// top down code
bool isSubSetSumTopDown(vector<int> &a, int sum, int n)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (isSubSetSumTopDown(a, k, n))
        cout << "YES\n";
    else
        cout << "NO\n";
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
