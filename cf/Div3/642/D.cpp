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
  vi a(n+1);
  queue<pii> q;
  int i=1;
  q.push(mp(1,n));
  while(!q.empty()) {
    pii p = q.front();
    q.pop();
    int mid = (p.ff+p.ss)/2; 
    a[mid] = i++;
    if((p.ss - mid) > (mid - p.ff)) {
      if(!(mid+1 > p.ss))
        q.push(mp(mid+1, p.ss));
      if(!(p.ff > mid-1))
      q.push(mp(p.ff, mid-1));
    } else {
      if(!(p.ff > mid-1))
        q.push(mp(p.ff, mid-1));
      if(!(mid+1 > p.ss))
        q.push(mp(mid+1, p.ss));
    }
  }
  Fori(i, 1, n+1) 
    cout << a[i] << " ";
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
