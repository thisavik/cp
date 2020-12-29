#include <bits/stdc++.h>
using namespace std;

int dp[(int)1e5+1];

int solve(int *h, int n, int k)
{
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    int op = 1e9;
    for(int i = 1; i <= min(n, k); i++)
        op = min(op, solve(h, n-i, k) + abs(h[n]-h[n-i]));
    return dp[n] = op;
}

int main() {
    int t = 1;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	int h[n];
    	for(int &val : h) 
    	    cin >> val;
    	memset(dp, -1, sizeof dp);
    	cout << solve(h, n-1, k);
    }
	return 0;
}