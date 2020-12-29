#include <bits/stdc++.h>

using namespace std;
#define int long long

int solve1(int n)
{
    int ans = 0;
    for(int i = 1; i <= n; i *= 10)
    {
        int x = n-i+1;
        ans += x;
    }
    cout << "\n";
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    cout << solve1(n);
	return 0;
}
