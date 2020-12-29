#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int64_t x;
        cin >> x;
        // find a, b such that (a & b) + (a | b) = x
        // one of the answer
        cout << 0 << " " << x << "\n";
        // another answer can be
        // cout << x/2 << " " << x-x/2 << "\n";
    }
}