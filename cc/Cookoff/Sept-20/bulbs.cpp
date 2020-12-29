#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<int> v;
    int start = 0, end = 0;
    int s = 0, e = 0;
    while(e < n)
    {
        if(str[e] == '0')
        {
            s = e;
            while(e < n && str[e] == '0')
                e++;
            if(s == 0)
                start = e-s;
            else if(e == n)
                end = e-s;
            else
                v.push_back(e-s);
        }
        else
        {
            while(e < n && str[e] == '1')
                e++, s = e;
        }
    }
    sort(v.begin(), v.end());
    while(k > 0)
    {
        if(start == 0 && end == 0 && v.size() == 0)
            break;
        if(k == 1)
        {
            if(start == max(start, end))
                start = 0;
            else
                end = 0;
            k--;
        }
        else
        {
            if(k % 2 == 0 && start+end > v.back())
                start = 0, end = 0, k-=2;
            else if(min(start, end) > v.back())
            {
                if(start == max(start, end))
                    start = 0;
                else
                    end = 0;
                k-=1;
            }
            else
                v.pop_back(), k-=2;
        }
    }
    int ans = start+end;
    for(int val : v)
        ans += val;
    cout << ans << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
/*
1
12 3
000100001000
*/