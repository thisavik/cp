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
  int n, k;
  cin >> n >> k;
  vi a(n), w(k);
  for(int i=0; i<n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  for(int i=0; i<k; i++)
    cin >> w[i];
  sort(w.begin(), w.end());
  vector<vector<int>> ans (k, vector<int>());
  for(int i=0; i<k; i++)
    ans[i].push_back(a[n-i-1]); 
  int j = n-k-1, z=0;
  while(z<k) {
    int i = ans[z].size();
    while(i<w[z] && j>=0) {
      ans[z].push_back(a[j]);
      i++;
      j--;
    }
    z++;
  }
  for(auto& v: ans) {
    for(int& val :v)
      cout << val << " ";
    cout << "\n";
  }
  int res = 0;
  for(int i=0; i<k; i++) {
    int mx = *max_element(ans[i].begin(), ans[i].end());
    int mn = *min_element(ans[i].begin(), ans[i].end());
    res += (mx + mn);
  }
  cout << res << "\n";
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