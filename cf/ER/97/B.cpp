#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int s = 0, e = 0, cnt = 0;
    while(e < n)
    {
        while(e+1 < n && str[e] != str[e+1])
            e++;
        e++;
        if(e >= n)
            break;
        s = e;
        char ch = (str[s] == '0' ? '1' : '0');
        while(e < n)
        {
            if(e+1 < n && str[e] == str[e+1] && str[e] == ch)
                break;
            e++;             
        }
        int ss = s, ee = (e == n ? n-1 : e);
        if(ss < ee)
            cnt++;
        while(ss < ee)
            swap(str[ss], str[ee]), ss++, ee--;
        e--;
    }
    cout << cnt << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}