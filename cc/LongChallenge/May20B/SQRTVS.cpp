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
  int n, m, x, ans=0;
  cin >> n >> m;
  vi a(n+1) ,temp;
  Fori(i, 1, n+1) {
    cin >> a[i];
  }
  bool vis[n+1];
  vii arr;
  memset(vis, false, n+1);
  Fori(i, 1, n+1) { 
    int k=i;
    for(;i!=a[k] && !vis[k];) {
      temp.push_back(a[k]);
      vis[k]=true;
      k=a[k];
    }
    if(i == a[k] && !vis[k]) {
      temp.push_back(a[k]);
      arr.push_back(temp);
      temp.clear();
      vis[k]=true;
      k=a[k];
    }
  }
  Fori(i, 0, arr.size()) {
    ans+=(arr[i].size()-1);
  }
  cout << ans << "\n";
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
