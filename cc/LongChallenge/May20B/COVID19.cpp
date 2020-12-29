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
#define pii pair<int,int>
#define si set<int>
#define mii map<int, int>
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
	int n; 
  cin >> n;
  vi a(n, 0), v;
  Fori(i, n)
    cin >> a[i];
  int aff = 1;
  Fori(i, n-1) {
    if(a[i+1]-a[i] <= 2)
      aff++;
    else {
      v.push_back(aff);
      aff = 1;
    }
  }
  v.push_back(aff);
  cout << *min_element(v.begin(), v.end()) << " " << *max_element(v.begin(), v.end());
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
