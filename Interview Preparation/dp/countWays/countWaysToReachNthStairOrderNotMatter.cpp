// it is same problem as count number of ways but in this problem order does not matter
// means {1,2,1}, {2,1,1} ans {1,1,2} consider as 1 way

#include <iostream>

using namespace std;

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
  int dp[n+1] = {0};
  int steps[3] = {1, 2, 3};

  // base case
  dp[0]=1;

  // one by one we count number of ways by taking one step in consideration
  for(int i = 0; i < 3; i++)
    for(int j = steps[i]; j <= n; j++)
      dp[j] += dp[j-steps[i]];
  cout << dp[n] << "\n";
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}