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
bool check(string& s, int n, int k) {
  vi cnt(2, 0);
  Fori(i, 0, n)
    cnt[s[i]-'a']++;
  if(min(cnt[0], cnt[1]) <= k)
    return true;
  Fori(i, 0, s.size()-n) {
    cnt[s[i]-'a']--;
    cnt[s[n+i]-'a']++;
    if(min(cnt[0], cnt[1]) <= k)
      return true;    
  }
  return false;
}
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int l=1, h=n, ans=0;
  while(l<=h) {
    int mid=l+(h-l)/2;
    if(check(s, mid, k)) {
      ans=max(ans,mid);
      l=mid+1;
    } else {
      h=mid-1;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  tool();
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}
