#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> Q(n);
    for(int &val: Q)
        cin >> val;
    int ans = 1, sum = Q[0];
    while(sum >= k*ans && ans < n)
    {
        sum += Q[ans];
        ans++;
    }
    if(sum >= k*ans)
    {
        int x = sum-k*ans;
        ans += x/k+1;
    }
    // while(sum >= k*ans)
    //     ans++;
    cout << ans << "\n";
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

/*
2 
6 5 
5 5 5 5 5 4 
2 1
100 100
*/