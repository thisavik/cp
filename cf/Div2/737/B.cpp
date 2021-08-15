/*
 *  author: thisavik
 *  created: 20:29:15 09-08-2021 Mon
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/thisa/OneDrive/Documents/cp/input.txt", "r", stdin);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/output.txt", "w", stdout);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/error.txt", "w", stderr);
#endif
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    rep(i, n)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    vector<int> temp = a;
    sort(all(temp));
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (mp[temp[i]] != mp[temp[i - 1]] + 1)
            cnt++;
    }
    cout << (cnt <= k ? "Yes" : "No") << "\n";
}

int32_t main(int32_t argc, char *args[])
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}