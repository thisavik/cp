#include <bits/stdc++.h>
using namespace std;
#define int long long

void tool()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// recursive approach

// int power(int a, int p) {
// 	if (p == 0)
// 		return 1;
// 	int ans = power(a, p / 2);
// 	ans = (p & 1) ? (ans * ans * a) : (ans * ans);
// 	return ans;
// }

// iterative approach

int power(int a, int p)
{
	int res = 1;
	while (p)
	{
		if (p & 1)
			res *= a;
		p = p >> 1; // or p = p/2;
		a = a * a;
	}
	return res;
}
void solve()
{
	int a, p;
	cin >> a >> p;
	cout << power(a, p) << "\n";
}
int32_t main()
{
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}