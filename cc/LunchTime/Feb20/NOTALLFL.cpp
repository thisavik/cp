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
#define pi pair<int,int>
#define si set<int>
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
	int n, k;
	cin >> n >> k;
	vi a(n), freq(k + 1, 0);
	int s, e, mx = INT_MIN, diff;
	s = e = diff = 0;
	loop(n) {
		cin >> a[i];
	}
	for (e = 0; e < n; e++)
	{
		freq[a[e]]++;
		if (freq[a[e]] == 1)
			diff++;
		while (diff >= k)
		{
			freq[a[s]]--;
			if (freq[a[s]] == 0)
				diff--;
			s++;
		}
		mx = max(mx, e - s + 1);
	}
	cout << mx << endl;
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
