#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int johnSum = 0, jackSum = 0;
    for(int &val: a)
        cin >> val, johnSum += val;
    for(int &val: b)
        cin >> val, jackSum += val;
    if(johnSum > jackSum)
    {
        cout << 0 << "\n";
        return;
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int ans = 0;
    for(int i = 0; i < min(n, m); i++)
    {
        johnSum -= a[i];
        johnSum += b[i];

        jackSum -= b[i];
        jackSum += a[i];
        ans++;
        if(johnSum > jackSum)
        {
            cout << ans << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}