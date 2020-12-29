#include <iostream>

using namespace std;
#define int long long
#define mod (int)1e9 + 7
const int maxN = 1e3 + 1;
int dp[maxN][maxN];
bool grid[maxN][maxN];

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main()
{
    tool();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            // 1 empty cell, 0 means trap
            grid[i][j] = (ch == '.') ? 1 : 0;
            dp[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
        if (grid[0][i])
            dp[0][i] = 1;
        else
            break;
    for (int i = 0; i < n; i++)
        if (grid[i][0])
            dp[i][0] = 1;
        else
            break;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j])
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n - 1][n - 1];
}