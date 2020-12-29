#include <iostream>
using namespace std;

int main() {
    int t = 1;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	int h[n];
    	for(int &val : h) 
    	    cin >> val;
    	int dp[n] = {0};
    	for(int i = 1; i < n; i++)
    	{   
    	    dp[i] = 1e9;
    	    for(int j = 1; j <= min(k, i); j++)
    	    {
    	        dp[i] = min(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
    	    }
    	}
    	cout << dp[n-1];
    }
	return 0;
}