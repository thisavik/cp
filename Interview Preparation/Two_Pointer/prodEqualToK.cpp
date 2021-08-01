//..................................................................................
// problem is you are given an array and a number k,
// you just need to find number of subarray exit in array have product equal to k.
//..................................................................................

/*
	a = (1, 1, 2, 3, 4, 1, 1)
	ans = {
		{1, 1, 2, 3, 4},
		{1, 1, 2, 3, 4, 1},
		{1, 1, 2 ,3, 4, 1, 1},
		{1, 2, 3, 4}
		{1, 2, 3, 4, 1}
		{1, 2, 3, 4, 1, 1}
		{2, 3, 4}
		{2, 3, 4, 1}
		{2, 3, 4, 1, 1}
	}

*/

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
	int s, e, res, p, onesCnt;
	s = e = res = onesCnt = 0; p = 1;
	for (; e < v.size(); e++) {
		p *= v[e];
		// case when product is greater than K
		while (s < e && p > k) {
			p /= v[s];
			s++;
		}
		if (p == k) {
			// count preceeding 1ns in subarray contributing in solution
			while (e + 1 < v.size() && v[e + 1] == 1) {
				onesCnt++;
				e++;
			}
			res += (onesCnt + 1);
			while (s <= e && v[s] == 1) {
				// as much as precedding term is 1 that much subarray is possible
				res += onesCnt + 1;
				s++;
			}
			p /= v[s];
			s++;
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