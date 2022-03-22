/*
 *  author: thisavik
 *  created: 16:04:54 03-03-2022 Thu
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define trace(...) 42
#endif

#define int int64_t
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

pair<int, int> extendedEuclid(int a, int b)
{
	if (b == 0)
	{
		return {1, 0};
	}
	auto &&[x1, y1] = extendedEuclid(b, a % b);
	int x = y1;
	int y = x1 - (a / b) * y1;
	return {x, y};
}

int modInverse(int a, int m)
{
	auto &&[b, q] = extendedEuclid(a, m);
	return (b + m) % m;
}

int32_t main()
{
	int a, m;
	cin >> a >> m;
	cout << modInverse(a, m) << "\n";
	return 0;
}

/**
 * modulo multiplicative inverse of a number A is defined as
 * (A*B) % mod = 1, B here is mod mul inverse of A
 * can wrute as (A*B - 1) % mod = 0
 * (A*B - 1) is divisible by mod
 * A*B - 1 = mod*Q, Q is any quotient
 * A*B + m*Q = 1, we have not this equation
 * show B exist only when A, m are coprime means gcd(A, m) = 1
 * B can we find using extended euclidean algorithm
 */