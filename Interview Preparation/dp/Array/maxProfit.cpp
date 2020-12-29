#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)

const int mxN = 1e5 + 1;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    // dp1[i] contain a[i] considering all cases, similarly dp2[i] contain b[i]
    vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
    range(i, 1, n)
    {
        int op1, op2, op3;
        op1 = op2 = op3 = -1e9;
        if (i - 1 >= 0)
            op1 = dp2[i - 1];
        if (i - 2 >= 0)
            op2 = dp2[i - 2] + max(a[i - 2], b[i - 2]);
        if (i - 3 >= 0)
            op3 = dp2[i - 3] + max(a[i - 3], b[i - 3]) + max(a[i - 2], b[i - 2]);
        dp1[i] = max({op1, op2, op3}) + a[i - 1];
        op1 = op2 = op3 = -1e9;
        if (i - 1 >= 0)
            op1 = dp1[i - 1];
        if (i - 2 >= 0)
            op2 = dp1[i - 2] + max(a[i - 2], b[i - 2]);
        if (i - 3 >= 0)
            op3 = dp1[i - 3] + max(a[i - 3], b[i - 3]) + max(a[i - 2], b[i - 2]);
        dp2[i] = max({op1, op2, op3}) + b[i - 1];
    }
    cout << max(dp1[n], dp2[n]) << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}