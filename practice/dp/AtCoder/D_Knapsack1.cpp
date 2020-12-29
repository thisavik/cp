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

int32_t main()
{
	tool();
	int t;
	cin >> t;
	while (t--)
	{
		int n, W;
		cin >> n >> W;
		int w[n], v[n];
		for (int i = 0; i < n; i++)
			cin >> w[i] >> v[i];
		int dp[n + 1][W + 1];
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= W; j++)
			{
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else
				{
					int op1 = dp[i - 1][j];
					int op2 = (j >= w[i - 1]) ? (dp[i - 1][j - w[i - 1]] + v[i - 1]) : -1e9;
					dp[i][j] = max(op1, op2);
				}
			}
		}
		cout << dp[n][W] << "\n";
	}
	return 0;
}

/*
3
3 8
3 30
4 50
5 60
5 5
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
6 15
6 5
5 6
6 4
6 6
3 5
7 2
*/