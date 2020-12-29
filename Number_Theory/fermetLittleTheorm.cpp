// it states as if p is a prime number then for any number a, a^p-a is divisible by p.
// a^p = a(mod p)
// if a is not divisible by p then we can also write is as
// a^(p-1) = 1(mod p)
// so a^(-1) = a^(p-2)(mod p)

// this gives modulo inverse of a as a^(p-2)(mod p)
// only applicable when a and p are relatively coprime, and p is prime

#include <bits/stdc++.h>

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

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int power(int a, int p, int m) {
	if (p == 0)
		return 1;
	a %= m;
	int ans = power(a, p / 2, m) % m;
	ans = (ans * ans) % m;
	return (p & 1) ? (ans * a) % m : ans ;
}

int modInverse(int a, int p) {
	if (gcd(a, p) != 1)
		return 0;
	return power(a, p - 2, p); // return a^(p-2)(mod p)
}

void solve() {
	int a, p;
	cin >> a >> p;
	cout << modInverse(a, p) << "\n";
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}