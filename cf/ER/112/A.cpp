/*
 *  author: thisavik
 *  created: 19:58:53 30-07-2021 Fri
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
  int n;
  cin >> n;
  int ans = 0;
  if(n < 6)
    cout << 15 << "\n";
  else if(n % 6 == 0)
    cout << (n/6) * 15 << "\n";
  else {
    int d = n/6;
    int rem = n % 6;
    if(rem <= 2)
      ans += (d-1)*15 + 20;
    else if(rem <= 4)
      ans += (d-1)*15 + 25;
    else
      ans += d*15 + 15;
    cout << ans << "\n";
  }
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
  while (t--)
    solve();
  return 0;
}