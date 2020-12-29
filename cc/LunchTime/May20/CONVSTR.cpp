#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define MOD (int)10e9+7
#define endl "\n"
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define si set<int>
#define mii map<int, int>
#define Fori(i, a, n) for(int i=a; i<n; i++)
#define Forj(j, a, n) for(int j=a; j<n; j++)
#define Fork(i, a, n) for(int i=a; i<n; i++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
void solve() {
	int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  // check a[i] < b[i]
  Fori(i, 0, n)
    if(a[i] < b[i]) {
      cout << -1 << "\n";
      return;
    }
  // check whether all element in b is present in a or not
  vector<bool> present(26, false);
  for(char& ch: a)
    present[ch - 'a'] = true;
  for(char& ch: b)
    if(!present[ch-'a']) {
      cout << -1 << "\n";
      return;
    }
  // in all other case answer exist
  vii res;
  for(char ch = 'z'; ch >= 'a'; ch--) {
    vi s;
    for(int i=0; i<n; i++)
      if(a[i]!=b[i]&&b[i]==ch)
        s.push_back(i);
    if(!s.empty()) {
      for(int i=0; i<n; i++)
        if(a[i] == ch)
          s.push_back(i);
      res.push_back(s);
    }
  }
  cout << res.size() << "\n";
  for(vi& v: res) {
    cout << v.size();
    for(int& val: v) 
      cout << " " << val;
    cout << "\n";
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
