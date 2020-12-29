// problem is minimum swap required to convert one array to another one have identical and unique elements in it

// e.g A1 = [2,3,4,5]
// A2 = [4,3,5,2]
// we have to convert A1 to A2 with minimum swap in A1


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
#define Fori(i, a, n) for(int i=a; i<n; i++)
#define Forj(j, a, n) for(int j=a; j<n; j++)
#define ForG(k, a, n) for(int k=a; k<n; k++)
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

void solve() {
  int n;
  cin >> n;
  vi a1(n), a2(n), b1(n), b2(n);;
  mii m;
  Fori(i, 0, n) {
    cin >> a1[i];
    m[a1[i]] = i;
  }
  Fori(i, 0, n) {
    cin >> a2[i];
    b2[i]=i;
    b1[i]=m[a2[i]];
  }
  // now we have to reach b1[] to b2[] with minimum number of swap.
  // ultimatly we have to sort b1[] with minimum number of swap. 
  // so, b2 can we omitted from the code, as of no more use
  int cnt=0;
  Fori(i, 0, n) {
    while(b1[i] != i) {
      swap(b1[i], b1[b1[i]]);
      cnt++;
    }
  } 
  Fori(i, 0, n) 
    cout << b1[i] << " ";
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