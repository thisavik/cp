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
#define ForI(i, a, n) for (int i = a; i < n; i++)
#define ForJ(j, a, n) for (int j = a; j < n; j++)
#define ForK(k, a, n) for (int k = a; k < n; k++)
#define ForR(i, n, a) for (int i = n-1; i>=a, i--)
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
  int sum=0, ans;
  for(int& val: a) {
    cin >> val;
    sum+=val;
  }
  if(sum%x!=0)
    ans = n;
  else {
    int l=0, r=0;
    ForI(i, 0, n)
      if(a[i]%x==0)
        l++;
      else
        break;
    ForI(i, 0, n) 
      if(a[n-i-1]%x==0)
        r++;
      else
        break;
    ans = max(n-l-1, n-r-1);
    if(ans <= 0)
      ans = -1;
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
