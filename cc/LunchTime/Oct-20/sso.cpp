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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &val : a)
            cin >> val;
        vector<int> bitCnt(32, 0);
        for (int val : a)
        {
            for (int i = 0; i < 32 && val > 0; i++)
            {
                bitCnt[i] += (val & 1);
                val >>= 1;
            }
        }
        int64_t ans = 0ll, mul = 1ll;
        for (int i = 0; i < 32; i++)
        {
            if (i)
                bitCnt[i] += bitCnt[i - 1] / 2;
            if (bitCnt[i])
                ans += mul;
            mul *= 2ll;
        }
        cout << ans << "\n";
    }
}
/*
2
2
1 1
3
1 9 8
*/