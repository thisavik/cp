#include <iostream>
using namespace std;

int main() {
    int t = 1;
    while(t--)
    {
    	int n;
    	cin >> n;
    	int h[n];
    	for(int &val : h) 
    	    cin >> val;
    	int dp[n] = {0};
    	for(int i = 1; i < n; i++)
    	{
    	    int op1, op2;
    	    op1 = op2 = 1e9;
    	    if(i-2 >= 0)
    	        op1 = dp[i-2] + abs(h[i]-h[i-2]);
    	    if(i-1 >= 0)
    	        op2 = dp[i-1] + abs(h[i]-h[i-1]);
    	    dp[i] = min(op1, op2);
    	}
    	cout << dp[n-1];
    }
	return 0;
}