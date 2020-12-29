#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define rep(i, n) for(long long i = 0; i < n; i++)
#define range(i, a, b) for(long long i = a; i <= b; i++)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
const int mxN = 1e5+5;
void solve()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    if(n == 2)
    {
        cout << -1 << "\n";
        return;
    }
    vector<int> ans(mxN, 0);
    ans[1] = 2, ans[2] = 3, ans[3] = 1;
    range(i, 4, n)
    {
        ans[i] = i;
    }
    for(int i = 3; i < n; i++)
    {
        if(!(ans[i]&ans[i+1]))
        {
            swap(ans[i+1], ans[i+2]);
        }
    }
    if(!(ans[n]&ans[n-1]))
        cout << -1;
    else
        range(i, 1, n)
            cout << ans[i] << " ";
    cout << "\n";
}

int32_t main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}