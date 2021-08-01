/*
 *  author: thisavik
 *  created: 19:57:28 30-07-2021 Fri
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int &val: a)
    cin >> val;
  for(int &val: b)
    cin >> val;
  if(n == 1)
  {
    cout << 0 << "\n";
    return;
  }
  vector<int> prefixA(n);
  prefixA[0] = a[0];
  vector<int> prefixB(n);
  prefixB[0] = b[0];
  for(int i = 1; i < n; i++)
  {
    prefixA[i] = prefixA[i-1]+a[i];
    prefixB[i] = prefixB[i-1]+b[i];
  }
  int ans = prefixA[n-1] - prefixA[0];
  for(int i = 1; i < n; i++) 
  {
    int op1 = prefixA[n-1] - prefixA[i];
    int op2 = prefixB[i-1];
    int mx = max(op1, op2);
    ans = min(ans, mx);
  }
  cout << ans << "\n";
}

int32_t main(int32_t argc, char *args[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
  int t;
  cin >> t;
  while(t--)
    solve(); 
  return 0;
}