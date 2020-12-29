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
  int m;
  cin >> m;
  int n = s.size();
  sort(s.begin(), s.end());
  map<char, int> cntChar;
  for(char& ch: s)
    cntChar[ch]++;
  vi b(m);
  Fori(i, 0, m) {
    cin >> b[i];
  }
  vector<char> res(m, '0');
  int j=n-1;
  while(1) {
    vi zCnt;
    for(int i=0; i<m; i++) 
      if(b[i] == 0)
        zCnt.push_back(i);
    if(zCnt.size() == 0) {
      break;
    }
    while(cntChar[s[j]] < zCnt.size()) {
      j-=cntChar[s[j]];
    }
    for(int i=0; i<m; i++) {
      if(b[i] == 0) {
        res[i] = s[j];
        b[i] = -1;
      } else {
        for(int& val: zCnt) {
          b[i] -= abs(i-val);
        }
      }
    }
    j-=cntChar[s[j]];
  }
  for(char& ch: res)
    cout << ch;
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