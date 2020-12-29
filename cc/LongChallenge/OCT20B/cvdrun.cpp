#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    k %= n;
    bool infected[n] = {false};
    while(!infected[x])
    {
        infected[x] = true;
        x = (x+k)%n;
    }
    cout << (infected[y] ? "YES\n" : "NO\n");
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}