#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define MOD 10e9+7
#define endl "\n"
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define si set<int>
#define mi map<int, int>
#define loop(n) for(int i=0; i<n; i++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void solve() {
	int n, q, ans = 0, f, dl = 0, dc;
	cin >> n >> q;
	loop((q)) {
		cin >> f >> dc;
		ans += abs(dl - f);
		ans += abs(f - dc);
		dl = dc;
	}
	cout << ans << endl;
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
