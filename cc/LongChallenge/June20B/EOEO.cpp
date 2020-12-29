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
  int n;
  cin >> n;
  if(n&1) {
    cout << n/2 << "\n";
    return;
  }
  int temp = n, cnt=0;
  while(temp%2 == 0) {
    temp/=2;
    cnt++;
  }
  temp = power(2, cnt+1);
  if(temp >= n) {
    cout << 0 << "\n";
    return;
  }
  cout << n/temp << "\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
