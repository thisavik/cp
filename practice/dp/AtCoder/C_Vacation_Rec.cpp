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

int dp[(int)1e5+1][3];

int solve(int value[][3], int n, int k)
{
    if(n == 0)
        return 0;
    
    if(dp[n][k] != -1)
        return dp[n][k];
    int op1, op2;

    if(k == 0)
    {
        op1 = solve(value, n-1, 1);
        op2 = solve(value, n-1, 2);
    }
    if(k == 1)
    {
        op1 = solve(value, n-1, 0);
        op2 = solve(value, n-1, 2);
    }
    if(k == 2)
    {
        op1 = solve(value, n-1, 0);
        op2 = solve(value, n-1, 1);
    }

    return dp[n][k] = value[n-1][k] + max(op1, op2);
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
        memset(dp, -1, sizeof dp);
        cout << max({solve(value, n, 0), solve(value, n, 1), solve(value, n, 2)}) << "\n";
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