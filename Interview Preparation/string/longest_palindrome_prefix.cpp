#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

void solve();
vector<int> LPS(string &);

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

void solve()
{
    string s;
    cin >> s;
    cout << s << "\n";
    string t = s + '$';
    reverse(s.begin(), s.end());
    t += s;
    cout << t << "\n";
    vector<int> lps = LPS(t);
    for(int val: lps)
        cout << val << " ";
    cout << "\n";
}

vector<int> LPS(string &s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    int i = 1, j = 0;
    while (i < n)
    {
        if (s[i] == s[j])
        {
            lps[i] = j + 1;
            i++, j++;
        }
        else
        {
            j == 0 ? i++ : j = lps[j - 1];
        }
    }
    return lps;
}