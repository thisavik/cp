//..................................................................................
// problem is you are given an array and a number k,
// you just need to find number of subarray exit in array have product less than k.
//..................................................................................


#include <bits/stdc++.h>
using namespace std;
#define int long long
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int cntSubary(vector<int>& v, int& k) {
	int s, e, res, p, len;
	s = e = res = 0; p = 1;
	for (; e < v.size(); e++) {
		p *= v[s];
		while (s < e && p >= k) {
			p /= v[s];
			s++;
		}
		if (p < k) {
			len = e - s + 1;
			res += len;
		}
	}
	return res;
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << cntSubary(v, k) << "\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}