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
  n = 2*n;
  vi a(n), even, odd;
  for(int i=0; i<n; i++) {
    cin >> a[i]; 
    if(a[i]&1)
      odd.push_back(i);
    else 
      even.push_back(i);
  }
  if(odd.size()%2 == 0 && odd.size() != 0) {
    odd.resize(odd.size()-1);
  }
  if(odd.size() == 0) {
    even.resize(even.size()-1);
  }
  for(int i=0; i+1<odd.size(); i+=2)
    cout << odd[i]+1 << " " << odd[i+1]+1 << "\n";
  for(int i=0; i+1<even.size(); i+=2)
    cout << even[i]+1 << " " << even[i+1]+1 << "\n";

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