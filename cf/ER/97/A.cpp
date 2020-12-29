#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    if(r >= 2*l)
        cout << "NO\n";
    else
        cout << "YES\n";
    
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}