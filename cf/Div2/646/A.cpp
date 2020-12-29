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
  int n, x;
  cin >> n >> x;
  vi a(n);
  int oCnt=0;
  for(int& val: a) {
    cin >> val;
    if(val&1)
      oCnt++;
  }
  int eCnt=n-oCnt;
  bool flag=false;
  for(int i=1; i<=oCnt && !flag; i+=2) {
    if(x>=i && x-i <= eCnt)
      flag=1;
  }
  if(flag)
    cout << "Yes\n";
  else
    cout << "No\n";
}
int32_t main()
{
  tool();
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
