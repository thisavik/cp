#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define MOD (int)10e9 + 7
#define endl "\n"
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define si set<int>
#define mii map<int, int>
#define Fori(i, a, n) for (int i = a; i < n; i++)
#define Forj(j, a, n) for (int j = a; j < n; j++)
#define Fork(k, a, n) for (int k = a; k < n; k++)

void tool()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("C://git//cp//input.txt", "r", stdin);
  freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

void solve()
{
  int a, b, c;
  cin >> a >> b >> c;
  if(b == 1 && a == c) {
    cout << -1 << " " << -1 << "\n";
    return;
  }
  if(a >= c) {
    cout << -1 << " " << b << "\n";
    return;
  } 
  if(a <= c/b) {
    cout << 1 << " " << -1 << "\n";
    return;
  }
  cout << 1 << " " << b << "\n";
}
int32_t main()
{
  tool();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}