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
  int n, k;
  string s;
  cin >> n >> k >> s;
  sort(s.begin(), s.end());
  // case 1st when k-1 th character is not same as 0th character in that case k-1 th char is ans
  if(s[0]!=s[k-1]) {
    cout << s[k-1];
  }
  // if all letters are same then we have to divide equally in all and take the max one
  else if(s[0] == s[n-1]) {
    Fori(i, n/k)
      cout << s[0];
    if(n%k != 0)
      cout << s[0];
  }
  // in all other cases we have append all the letters from kth index in ans
  else {
    cout << s[0];
    ForG(i, k, n) 
      cout << s[i];
  }
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
