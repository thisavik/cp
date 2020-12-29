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
  int p, q, r, a, b, c;
  cin >> p >> q >> r;
  cin >> a >> b >> c;
  int diff1 = a-p, diff2 = b-q, diff3 = c-r;
  int mul1 = 0, mul2 = 0, mul3 = 0;
  if(a!=0 && p!=0 && a%p==0)
    mul1 = a/p;
  if(b!=0 && q!=0 && b%q==0)
    mul2 = b/q;
  if(c!=0 && r!=0 && c%r==0)
    mul3 = c/r;
  int ans = 3;
  cout << mul1 << " " << mul2 << " " << mul3 << "\n";
// cases when answer is 0
  if(diff1 == diff2 && diff2 == diff3 && diff1 == 0) {
    cout << 0 << "\n";
    return;
  }

// cases when answer is 1
  if(diff1 == diff2 && diff2 == diff3) {
    cout << 1 << "\n";
    return;
  }
  if(mul1 == mul2 && mul2 == mul3 && mul1 != 0) {
    cout << 1 << "\n";
    return;
  }
  if(diff1 == 0 && (diff2 == diff3 || mul2 == mul3)) {
    cout << 1 << "\n";
    return;    
  }
  if(diff2 == 0 && (diff1 == diff3 || mul1 == mul3)) {
    cout << 1 << "\n";
    return;    
  }
  if(diff3 == 0 && (diff2 == diff1 || mul2 == mul1)) {
    cout << 1 << "\n";
    return;    
  }
// cases when answer is 2
  if(diff1 == diff2 || diff1 == diff3 || diff2 == diff3) {
    ans = 2;
  } 

  if(mul1 == mul2 || mul2 == mul3 || mul3 == mul1) {
    ans = 2;
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
