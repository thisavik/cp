#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define MOD (int)10e9+7
#define endl "\n"
#define pb push_back
#define mp make_pair
#define it iterator
#define pii pair<int,int>
#define si set<int>
#define mii map<int, int>
#define mci map<char, int>
#define Fori(i, a, n) for(int i=a; i<n; i++)
#define Forj(j, a, n) for(int j=a; j<n; j++)
#define ForG(k, a, n) for(int k=a; k<n; k++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

int dp[1001][1001];
bool isSubsetSumBottomUp(vi a, int sum, int n) {
  if(sum == 0) {
    return true;
  }
  if(sum!=0 && n==0) {
    return false;
  }
  if(dp[n][sum] != -1) {
    return dp[n][sum];
  }
  if(a[n-1] <= sum) {
    return dp[n][sum] = isSubsetSumBottomUp(a, sum-a[n-1], n-1) || isSubsetSumBottomUp(a, sum, n-1);
  } else {
    return dp[n][sum] = isSubsetSumBottomUp(a, sum, n-1);
  }
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	memset(dp, -1, sizeof(dp));
	Fori(i, 0, n)
		cin >> a[i];
	int sum = accumulate(a.begin(), a.end(), 0);
	cout << sum << "\n";
	if(sum&1)
		cout << "No\n";
	else
		cout << (isSubsetSumBottomUp(a, sum/2, n) ? "Yes" : "NO") << "\n";
	
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}