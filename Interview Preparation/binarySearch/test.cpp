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

void solve(vi& a, int x) {
  int l=0, h=a.size()-1, ans=-1, sum=0;
  while(l<=h) {
    int mid = l+(h-l)/2;
    if(a[mid] <= x) {
      ans=mid;
      l=mid+1;
    } else {
      h=mid-1;
    }
  }
  Fori(i, 0, ans+1)
    sum += a[i];
  cout << ans+1 << " " << sum << "\n";
}

int32_t main() {
	tool();
	int n;
	cin >> n;
  vi a(n);
  Fori(i, 0, n) 
    cin >> a[i];
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  Fori(i, 0, q) {
    int x;
    cin >> x;
    solve(a, x); 
  }
	return 0;
}
