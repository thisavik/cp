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
#define Fori(i, n) for(int i=0; i<n; i++)
#define Forj(j, n) for(int j=0; j<n; j++)
#define ForG(i, a, n) for(int i=a; i<n; i++)
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
  vi a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  for(int i=0; i<q; i++) {
    int k;
    cin >> k;
    if(k>0) {

    }
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
