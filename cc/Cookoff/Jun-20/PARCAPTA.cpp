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

int power(int n, int p) {
  if(p == 0) 
    return 1;
  int ans = power(n, p/2);
  ans *= ans;
  if(p&1)
    ans *= n;
  return ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n), b(n);
  for(int& val: a)
    cin >> val;
  for(int& val: b)
    cin >> val;
  vector<pii> v;
  Fori(i, 0, m) {
    int x, y;
    cin >> x >> y;
    v.push_back(mp(x, y));
  }
  int x=a[0]/b[0];
  for(int i=0; i<n; i++)
    x = max(a[i]/b[i], x);
  vi possible;
  for(int i=0; i<n; i++) {
    if(x = a[i]/b[i])
      possible.push_back(i+1);
  }
  
  vi res;
  cout << res.size() << "\n";
  for(int& val: res)
    cout << val << " ";
  cout << "\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
