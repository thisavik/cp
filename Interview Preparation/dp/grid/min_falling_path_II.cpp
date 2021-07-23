#include <iostream>

using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int dp[n][n];
    for (int i = 0; i < n; i++)
        dp[0][i] = a[0][i];

    for (int i = 1; i < n; i++)
    {
        int fMin = INT32_MAX, sMin = INT32_MAX, posFmin = -1;
        for (int j = 0; j < n; j++)
        {
            if (dp[i - 1][j] < fMin)
            {
                sMin = fMin;
                fMin = dp[i - 1][j];
            }
            else if (dp[i - 1][j] < sMin)
                sMin = dp[i - 1][j];
        }
        cout << fMin << " " << sMin << "\n";
        for (int j = 0; j < n; j++)
        {
            if (j != posFmin)
                dp[i][j] = a[i][j] + fMin;
            else
                dp[i][j] = a[i][j] + sMin;
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}