#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector <int> h(n);
    for(int &val: h)
        cin >> val;
    sort(h.rbegin(), h.rend());
    int mike = 0, tracy = 0, i = 0;
    while(i < n && mike < k && tracy < k)
    {
        int d1 = (mike + h[i]) - tracy;
        int d2 = (tracy + h[i]) - mike;
        if(d1 > d2)
            tracy += h[i];
        else
            mike += h[i];
        cout << mike << " " << tracy << "\n";
        i++;
    }
    while(i < n && mike < k)
        mike += h[i], i++;
    while(i < n && tracy < k)
        tracy += h[i], i++;
    if(mike >= k && tracy >= k)
        cout << i << "\n";
    else
        cout << -1 << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}