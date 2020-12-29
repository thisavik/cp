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
  int top = 1, down = n, left = 1, right = n;
  int ans[n+1][n+1];
  memset(ans, 0, sizeof(ans));
  int k=1;
  while(k <= n*n) {
    for(int i = left; i <= right; i++)
      ans[top][i] = k++;
    top++;
    for(int i = top; i<= down; i++)
      ans[i][right] = k++;
    right--;
    for(int i=right; i>= left; i--)
      ans[down][i] = k++;
    down--;
    for(int i=down; i>=top; i--)
      ans[i][left] = k++;
    left++;
  }
  for(int i = 1; i <=n; i++) {
    for(int j = 1; j <= n; j++)
      cout << ans[i][j] << " ";
    cout << "\n";
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
