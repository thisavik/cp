/*
 *  author: thisavik
 *  created: 20:32:08 30-07-2021 Fri
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
  int W, H;
  cin >> W >> H;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int wt = x2-x1, ht = y2-y1;
  int w, h;
  cin >> w >> h;
  int ans;
  if(w+wt > W && h+ht > H)
  {
    cout << -1 << "\n";
    return;
  }
  else if(w+wt > W && h+ht <= H)
    ans = min(h-y1, y2+h-H);
  else if(h+ht > H && w+wt <= W)
    ans = min(w-x1, x2+w-W);
  else
    ans = min({h-y1, y2+h-H, w-x1, x2+w-W});
  if(ans < 0)
    ans = 0;
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