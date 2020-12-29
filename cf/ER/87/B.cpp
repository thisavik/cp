#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define MOD (int)10e9+7
#define endl "\n"
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define si set<int>
#define mii map<int, int>
#define Fori(i, n) for(int i=0; i<n; i++)
#define Forj(j, n) for(int j=0; j<n; j++)
#define ForG(i, a, n) for(int i=a; i<n; i++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
bool all(vi& m) {
  if(m[1]!=0 && m[2]!=0 && m[3]!=0)
    return true;
  return false;
}
void solve() {
  string str;
  cin >> str;
  int n=str.size();
  vi m(4);
  int s=0, e=0, mn=INT_MAX;
  for(e=0; e<n; e++) {
    m[str[e]-'0']++;
    if(!all(m)) {
      if(m[str[e]-'0']!=0) {
        if(str[e-1] != str[e]) {
          m[str[e]-'0'] = 1;
          m[str[e-1]-'0'] = 1;
          s=e-1;
        }
        else {
          m[str[e]-'0'] = 1;
          s=e;
        }
      }
    } else {
      mn = min(mn, e-s+1);
      while(all(m) && s<=e) {
        m[str[s]-'0']--;
        s++;
      }
      while(m[str[s]-'0'] > 1 && s<=e) {
        m[str[s]-'0']--;
        s++;
      }
    }
  } 
  cout << mn << "\n";
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
