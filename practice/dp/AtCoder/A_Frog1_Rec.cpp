#include <bits/stdc++.h>
using namespace std;

int dp[(int)1e5+1];

int solve(int *h, int n)
{
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    int op1, op2;
    op1 = op2 = 1e9;
    if(n >= 2)
        op1 = solve(h, n-2) + abs(h[n]-h[n-2]);
    if(n >= 1)
        op2 = solve(h, n-1) + abs(h[n]-h[n-1]);
    return dp[n] = min(op1, op2);
}

int main() {
    int t = 1;
    while(t--)
    {
    	int n;
    	cin >> n;
    	int h[n];
    	for(int &val : h) 
    	    cin >> val;
    	memset(dp, -1, sizeof dp);
    	cout << solve(h, n-1);
    }
	return 0;
}

/*
10 4
40 10 20 70 80 10 20 70 80 60
*/