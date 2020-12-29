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
  int n, k;
  cin >> n >> k;
  if(k >= n) 
    cout << "1\n";
  else {
    vector<int> d;
    for (int i=1; i<=sqrt(n); i++) { 
      if (n%i == 0) { 
        if(n/i == i)
          d.push_back(i);
        else {
          d.push_back(i);
          d.push_back(n/i);
        } 
      } 
    } 
    sort(d.begin(), d.end());
    for(int i=d.size()-1; i>=0; i--) {
      if(d[i] <= k) {
        cout << n/d[i] << "\n";
        break;
      }
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
