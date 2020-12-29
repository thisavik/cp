#include <iostream>
#include <cmath>
using namespace std;

#define mod (int)1e9+7

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
}

int power(int a, int p) {
	int res = 1;
	while (p) {
        a %= mod;
		if (p & 1)
			res *= a;
        res %= mod;
		p = p >> 1;
		a = a * a;
	}
	return res;
}

int main()
{
    tool();
    int l, h, k;
    cin >> l >> h;
    cin >> k;
    int s = h - l + 1;
    int bn = 0;
    int an = 0;
    if(s % 2 == 0)
        bn = an = s/2;
    else {
        if(l % 2 == 0)
            an = s/2 + 1, bn = s/2;
        else
            bn = s/2 + 1, an = s/2; 
    }
    int ans = power(bn + an, k);
    ans += power(an - bn, k);
    ans %= mod;
    ans = ans >> 1;
    cout << ans;
}