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
  int n;
  cin >> n;
  vi a(n);
  for(int& x: a)
		cin >> x;
	vi isAvail(3, 0);
	bool flag = true;
	for(int i=0; i<n && flag; i++) {
		if(i==0) {
			if(a[i] == 5) {
				isAvail[0]++;
			} else {
				flag = false;
			}
		} else {
			if(a[i] == 10) {
				if(isAvail[0]) {
					isAvail[0]--;
					isAvail[1]++;
				} else {
					flag = false;
				}
			} else if(a[i] == 15) {
				if(isAvail[1]) {
					isAvail[1]--;
					isAvail[2]++;
				} else if(isAvail[0] > 1) {
					isAvail[0]-=2;
					isAvail[2]++;
				} else {
					flag = false;
				}
			} else if(a[i] == 5) {
				isAvail[0]++;
			}
		}
	} 
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
