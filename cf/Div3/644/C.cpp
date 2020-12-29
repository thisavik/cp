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
  vector<int> a(n);
  for(int i=0; i<n; i++) 
      cin >> a[i];
  int oddCnt=0;
  for(int val: a)
    if(val&1)
      oddCnt++;
  if(!(1&oddCnt)) 
    cout << "YES" << "\n";
  else {
    sort(a.begin(), a.end());
    int flag = 1;
    for(int i=0; i<n-1 && flag; i++) {
      if(a[i+1]-a[i] == 1)
        flag = 0;
    }
    if(flag)
      cout << "NO" << "\n";
    else
      cout << "YES" << "\n";
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
