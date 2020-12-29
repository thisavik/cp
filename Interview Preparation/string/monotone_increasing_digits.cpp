#include <iostream>

using namespace std;

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
    int N;
    cin >> N;
    string s = to_string(N);
    int n = s.size();
    int i = 0;
    while(i+1 < n && s[i] <= s[i+1]) i++;
    while(0 < i && s[i] == s[i-1]) i--;
    if(i+1 != n) s[i] = --s[i];
    while(++i < n) s[i] = '9';
    n = stoi(s);
    cout << n;
}

int32_t main()
{
    tool();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}