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
  int n, m ,k;
  cin >> n >> m >> k;
  int ans = 0;
  int t = n/k;
  if(t >= m) {
    ans = m;
  } else {
    ans += t;
    if((m-t) <= (k-1))
      ans -= 1;
    else if((m-t)%(k-1) == 0) {
      ans -= (m-t)/(k-1);
    } else {
       ans -= (m-t)/(k-1) + 1;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
