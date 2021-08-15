/*
 *  author: thisavik
 *  created: 20:00:36 11-08-2021 Wed
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/thisa/OneDrive/Documents/cp/input.txt", "r", stdin);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/output.txt", "w", stdout);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/error.txt", "w", stderr);
#endif
}

void solve()
{
    int n, p, cnt = 0;
    cin >> n;
    string s;
    vector<int> v;
    set<int, greater<int>> st;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        st.insert(stoi(s));
    }
    for(auto &val: st)
        v.push_back(val);
    if(v[0] <= 0)
    {
        cout << 0 << "\n";
        return;
    }
    for(int i = 1; i < v.size(); i++) 
    {
        if(v[i] <= i && v[i-1] > i)
        {
            cout << i << "\n";
            return;
        }
    }
    if(v[v.size()-1] > v.size())
    {
        cout << v.size() << "\n";
        return;
    }
    cout << -1 << "\n";
}

int32_t main(int32_t argc, char *args[])
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}