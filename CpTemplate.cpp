#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)


const int mod = 1e9 + 7;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int power(int a, int p)
{
    if (p == 0)
        return 1;
    a %= mod;
    int ans = power(a, p / 2) % mod;
    ans = (ans * ans) % mod;
    return (p & 1) ? (ans * a) % mod : ans;
}

int addMod(vector<int> a)
{
    int res = 0;
    for (int val : a)
    {
        res = ((res % mod) + (val % mod)) % mod;
    }
    return res;
}

int mulMod(vector<int> a)
{
    int res = 1;
    for (int val : a)
    {
        res = ((res % mod) * (val % mod)) % mod;
    }
    return res;
}

int subMod(int a, int b)
{
    return ((a - b) % mod + mod) % mod;
}

int divMod(int a, int b)
{
    return ((a % mod) * (power(b, mod - 2) % mod)) % mod;
}

int nCr(int n, int r)
{
    int num = 1, den = 1;
    if (n - r < r)
        r = n - r;
    rep(i, r)
    {
        int Gcd = gcd(n - i, r - i);
        num = mulMod({num, (n - i) / Gcd});
        den = mulMod({den, (r - i) / Gcd});
        Gcd = gcd(num, den);
        num /= Gcd;
        den /= Gcd;
    }
    return num;
}

void solve()
{
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
