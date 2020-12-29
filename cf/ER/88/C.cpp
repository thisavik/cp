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
  int h, c, t;
  cin >> h >> c >> t;
  if(t == h) 
    cout << "1\n";
  else if(2*t<=(h+c))
    cout << "2\n";
  else {
    int x = (t-c)/(2*t-h-c);
    double pre = (x*h+(x-1)*c)/(2*x-1);
    double post = ((x+1)*h+x*c)/(2*x+1);
    if(abs(pre-t) >= abs(post-t))
      cout << (2*x-1) << "\n";
    else
      cout << (2*x+1) << "\n";
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
