/*
 *  author: thisavik
 *  created: 20:04:54 09-08-2021 Mon
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  rep(i, n)
    cin >> a[i], sum += a[i];
  int mx = *max_element(a.begin(), a.end());
  int cnt = 0;
  cout << mx + (sum-mx)/(n-1) << "\n";
}

int32_t main(int32_t argc, char *args[])
{
  int t;
  cin >> t;
  while(t--)
    solve(); 
  return 0;
}