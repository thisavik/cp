// C++ program to find multiplicative modulo inverse using
// Extended Euclid algorithm.
// applicable only when a, m are coprime

// ax + by = gcd(a,b) (Euclid extended gcd)
// if we write b = m then ax + ym = gcd(a,m)
// taking (mod m) both side (ax)(mod m) + (ym)(mod m) = gcd(a,m)(mod m)
// if a and m are coprime then (ax)(mod m) = 1 (mod m). so, x is nothing but modulo inverse of a...
// our task is to find x

#include<bits/stdc++.h>
using namespace std;

#define int long long

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int extendedGcd(int a, int b, int& x, int& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int gcd = extendedGcd(b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;
	return gcd;

}

int modInverse(int a, int m) {
	int x, y;
	return extendedGcd(a, m, x, y) != 1 ? 0 : (x + m) % m;
}

void solve() {
	int a, m;
	cin >> a >> m;
	cout << modInverse(a, m) << "\n";
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
