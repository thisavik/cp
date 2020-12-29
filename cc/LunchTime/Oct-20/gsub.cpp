#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &val : a)
            cin >> val;
        int ans = 1;
        for (int i = 1; i < n; i++)
            if(a[i] != a[i-1])
                ans++;
        for(int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            if(x > 0)
                ans -= (a[x] != a[x-1]);
            if(x+1 < n)
                ans -= (a[x] != a[x+1]);
            a[x] = y;
            if(x > 0)
                ans += (a[x] != a[x-1]);
            if(x+1 < n)
                ans += (a[x] != a[x+1]);
            cout << ans << "\n";
        }
    }
}
/*
1
5 2
1 1 2 5 2
1 3
4 2
*/