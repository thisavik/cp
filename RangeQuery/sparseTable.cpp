// program to do range minimum query using sparse table
// lookUp[i][j] contain minimum in range from arr[i] to arr[i+2^j-1]

#include <bits/stdc++.h>
using namespace std;

void tool()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

struct sparseTable
{
	vector<vector<int>> lookUp;
	int (*func)(int, int);
	sparseTable(vector<int> &a, int (*func)(int, int))
	{
		this->func = func;
		build(a);
	}
	void build(vector<int> &a)
	{
		int n = a.size();
		lookUp.resize(n, vector<int>((ceil)(log2(n)), 0));
		// calculate for 2^0 length subarray
		for (int i = 0; i < n; i++)
		{
			lookUp[i][0] = a[i];
		}
		// calculate for each 2^j length subarray
		for (int j = 1; (1 << j) <= n; j++)
		{
			for (int i = 0; i + (1 << j) <= n; i++)
			{
				// at index i if we want to calculate for 2^j length
				// then func( i for 2^(j-1) len, i + 2^(j-1) for 2^(j-1) len ) will give its answer
				lookUp[i][j] = func(lookUp[i][j - 1], lookUp[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int &l, int &r)
	{
		int i = log2(r - l + 1);
		// to calculate for l, r
		// we need to calculate func( l for 2^(i) len, r-2^i for 2^i len )
		return func(lookUp[l][i], lookUp[r - (1 << i)][i]);
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &val : a)
		cin >> val;
	sparseTable t(a, [](int x, int y) -> int
								{ return x < y ? x : y; });
	while (q--)
	{
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		x--, y--;
		cout << t.query(x, y) << "\n";
	}
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