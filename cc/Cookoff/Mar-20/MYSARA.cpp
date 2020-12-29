#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
void solve()
{
    int n;
    cin >> n;
    int b[n];
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }
    // check whether b[i-1] is subset of b[i]
    for(int i=1; i<n; i++)
        if(b[i]&b[i-1] != b[i-1])
        {
            cout << "0\n";
            return;
        }
    int cnt = 0;
    // count total number of set bits in b array
    for(int i=0; i<n; i++)
    {
        cnt += __builtin_popcount(b[i]);
    }
    // subtract 1st appearing set bit
    cnt -= __builtin_popcount(b[n-1]);
    int ans = 1;
    for(int i=1; i<=cnt; i++)
        ans = ans*2%MOD;
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
