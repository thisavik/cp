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
  string s;
  cin >> s;
  int ocnt = 0;
  for(char& ch: s)
    if(ch == '1')
      ocnt++;
  int n = s.size();
  int ans = 0;
  int zcnt=n-ocnt;
  if(s[0] != s[n-1])
    ans = min(zcnt, ocnt)-1;
  else if(s[0]==s[n-1]) {
      if(s[0]=='1')
        ans = min(zcnt, ocnt-1);
      else
        ans = min(ocnt, zcnt-1);
  }
  cout << ans << "\n";
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
