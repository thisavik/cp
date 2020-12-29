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
  vector<string> v(n);
  Fori(i, 0, n)
    cin >> v[i]; 
  // Fori(i, 0, n) {
  //   Forj(j, 0, n)
  //     cout << v[i][j];
  //   cout << "\n";
  // }
  int flag = 1;
  for(int i=0; i<n && flag; i++)
    for(int j=0; j<n && flag; j++) 
      if(v[i][j]-'0') {
        if(i<n-1 && j <n-1 && !((v[i+1][j]-'0') || (v[i][j+1]-'0'))) {
          flag = 0;
        } else if(i<n-1 && !(v[i+1][j])) {
          flag = 0;
        } else if(j<n-1 && !(v[i][j+1])) {
          flag = 0;
        }
      }
  if(flag)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
