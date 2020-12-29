#include <bits/stdc++.h>
using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

void solve()
{
    int n;
    cin >> n;
    int fre[26] = {0};
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(char ch : s)
            fre[ch-'a']++;
    }
    for(int i = 0; i < 26; i++)
        if(fre[i]%n != 0)
        {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
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