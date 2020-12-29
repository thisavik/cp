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
#define it iterator
#define pii pair<int,int>
#define si set<int>
#define mii map<int, int>
#define mci map<char, int>
#define Fori(i, n) for(int i=0; i<n; i++)
#define Forj(j, n) for(int j=0; j<n; j++)
#define ForG(k, a, n) for(int k=a; i<n; i++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}
void solve() {
  int X, Y, L, R;
  cin >> X >> Y >> L >> R;
  int XY = X|Y;
  if(X > Y)
    swap(X, Y); // for any case I want X <= Y
  if(X == 0) {
    cout << 0 << "\n";
    return;
  }
  bitset<63> x(X), y(Y), l(L), r(R), b;
  if(Y < R) {
    cout << XY;
  }
  else if(X < R) {
    bitset<63> temp(XY);
    for(int i=0; i<64; i++) {
     if(temp.to_ullong() > r.to_ullong()) {
       temp[i]=0;
     }
    }
    if(!(temp.to_ullong()&X)) {
      temp = bitset<63> (XY);
      for(int i=63; i>=0; i--) {
        if(temp.to_ullong() > r.to_ullong()) {
          temp[i]=0;
        }
      }
    }
    cout << temp.to_ullong();
  } else {
    bitset<63> temp(XY);
    for(int i=63; i>=0; i--) {
     if(temp.to_ullong() > r.to_ullong()) {
       temp[i]=0;
     }
    }
  }
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
