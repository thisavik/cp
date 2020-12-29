#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define si set<int>
#define mi map<int, int>
#define loop(n) for(int i=0; i<n; i++)
const int MOD = (int)1000000007;
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int power(int a, int p) {
	if (p == 0)
		return 1;
	int ans = power(a, p / 2) % MOD;
	ans = (ans * ans) % MOD;
	return (p & 1) ? (ans * a) % MOD : ans ;
}
void solve() {
	int n, a, ans = 0, p = 1;
	cin >> n >> a;
	ans = a;
	for (int i = 1; i < n; i++) {
		p = p * (2 * i);
		cout << ans << "\n";
		ans = ((power(power(a, p), 2 * i + 1)) + ans) % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
