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
#define Fori(i, a, n) for(int i=a; i<n; i++)
#define Forj(j, a, n) for(int j=a; j<n; j++)
#define Fork(i, a, n) for(int i=a; i<n; i++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
void solve() {
  int n, m;
  cin >> n >> m;
  set<int> s;
  vi v;
  Fori(i, 0, n) {
    string s;
    cin >> s;
    bitset<60> b(s);
    s.push_back(b.to_ullong());
    v.push_back(b.to_ullong());
  }
  int median = ((1<<m)-1)/2;
  bool even = 1;
  Fori(i, 0, n) {
    if(v[i]<median) {
      if(even) {
        while(s.find(++median)!=s.end());
        even=0;
      } else {
        even=1;
      }
    } else if(v[i]>median) {
      if(even) {
        even=0;
      } else {
        while(s.find(--median)!=s.end());
        even=1;
      }
    } else {
      if(even) {
        while(s.find(++median)!=s.end());
        even=0;
      } else {
        while(s.find(--median)!=s.end());
        even=1;
      }
    }
  }
  bitset<60> b(median);
  for(int i=m-1; i>=0; i--)
    cout << b[i];
  cout << "\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}


// 0 1 2 3 4 5 6 7 
// floor((8-1)/2) = 3 