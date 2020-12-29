// in this problem order in which steps are taken is taking into consideration

// let person can take 1 or 2 or 3 step at a time

#include <iostream>
#include <cstring>

using namespace std;

#define mod (int)1e9+7
#define maxN (int)1e5+1


void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("C://git//cp//input.txt", "r", stdin);
		freopen("C://git//cp//output.txt", "w", stdout);
	#endif
}

void solve() {
    int n;
    cin >> n;
    int dp[n+1]={0};

    // base case 
    dp[0]=1; dp[1]=1; dp[2]=2;

    // reaching a certain step depends on just below three step as we can reach at that place by 1, 2, 3 steps 
    for(int i = 3; i <= n; i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    cout << dp[n] << "\n";
}

int dp[maxN];
// using sliding window
void help(int *a, int n) {
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int sum = 0;
    for(int i = 1; i <= 3; i++)
        sum += dp[i];
    for(int i = 4; i < maxN; i++) {
        dp[i] = sum;
        dp[i] %= mod;
        sum += dp[i]-dp[i-3];
    }
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}