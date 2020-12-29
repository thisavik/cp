#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define MOD (int)10e9+7
#define endl "\n"
#define pb push_back
#define mp make_pair
#define it iterator
#define pii pair<int,int>
#define si set<int>
#define mii map<int, int>
#define mci map<char, int>
#define Fori(i, n) for(int i=0; i<n; i++)
#define Forj(j, n) for(int j=0; j<n; j++)
#define ForG(k, a, n) for(int k=a; i<n; i++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  mci m;
  Fori(i, n)
    m[s[i]]++;
  mci::it itr;
  while(q--) {
    int c, ans = 0;
    cin >> c;
    for(itr = m.begin(); itr != m.end(); itr++)
      if(itr->ss > c)
        ans += (itr->ss - c);
    cout << ans << "\n";
  }
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
