#include <iostream>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int k ;
    cin >> k;
    int n = s.size();
    string ans;
    for(int i = 0; i < n; i++)
    {
        while(!ans.empty() && ans.back() > s[i] && k > 0)
            ans.pop_back(), k--;
        ans.push_back(s[i]);
    }
    while(k--)
        ans.pop_back();
    while(ans.front() == '0')
        ans.erase(0, 1);
    cout << ans;
}

int32_t main()
{
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}