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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  char str[n][m];
  Fori(i, 0, n)
    Forj(j, 0, m)
      cin >> str[i][j];
  int cost = 0;
  Fori(i, 0, n) {
    for(int j=0; j<m;) {
      if(str[i][j] == '.') {
        if(j+1 < m && str[i][j] == str[i][j+1])
          cost += min(y, 2*x);
        else
          cost += x;
        j+=2;
      } else {
        j++;
      }
    }
  }
  cout << cost << "\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
