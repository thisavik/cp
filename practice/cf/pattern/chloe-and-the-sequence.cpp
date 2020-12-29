#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int64_t n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int64_t start = 1ll << (i-1), period = 1ll << i;
        if((k - start) % period == 0)
        {
            cout << i;
            return 0;
        } 
    }
}