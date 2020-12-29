// find minimum in a range [L, R]

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

void tool()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

struct sqrtDecom
{
	vector<int> sD;
	int BLK;
	// depends of problem requirement
	sqrtDecom(vector<int> &);
	int query(int, int, vector<int> &);
};

int32_t main()
{
	tool();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &val : a)
		cin >> val;
	sqrtDecom s(a);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int l, r;
		l--, r--;
		cin >> l >> r;
		cout << s.query(l, r, a) << endl;
	}
	return 0;
}

sqrtDecom::sqrtDecom(vector<int> &a)
{
	BLK = (int)sqrt(a.size()) + 1;
	sD.resize(BLK, 0);
	for (int i = 0; i < a.size(); i++)
	{
		sD[i / BLK] = min(sD[i / BLK], a[i]);
	}
}

int sqrtDecom::query(int l, int r, vector<int> &a)
{
	int lb = l / BLK, rb = r / BLK;
	int mn = INT_MAX;
	// full overlapp on original array
	if (lb == rb)
	{
		for (int i = l; i <= r; i++)
			mn = min(mn, a[i]);
	}
	else
	{
		// partial left part of original array
		for (int i = l; i < BLK * (lb + 1); i++)
			mn = min(mn, a[i]);
		// full overlapp
		for (int i = lb + 1; i < rb; i++)
			mn = min(mn, sD[i]);
		// partial right part of original array
		for (int i = BLK * rb; i <= r; i++)
			mn = min(mn, a[i]);
	}
	return mn;
}