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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int s1 = -1, e1 = -1;
  for(int i=0; i<n; i++)
    if(s[i] == '1') {
      s1 = i;
      break;
    }
  for(int i=n-1; i>=0; i--) 
    if(s[i] == '1')
      continue;
    else {
      e1 = i+1;
      break;
    }
  if(s1 == e1 || s1 == -1 || e1 == -1) {
    cout << s << "\n";
    return;
  }
  for(int i=0; i<s1; i++)
    cout << s[i];
  cout << "0";
  for(int i=e1; i<n; i++)
    cout << s[i];
  cout << "\n";
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