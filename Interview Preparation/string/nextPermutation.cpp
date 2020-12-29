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
#define Fork(k, a, n) for(int k=a; k<n; k++)
#define Forn(i, n) for(int i=n; i>=0; i--)

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

void solve() {
  string s;
  cin >> s;
  string t = s;
  cout << (next_permutation(t.begin(), t.end()) ? t : "-1") << "\n";

  int n=s.size(), pos=-1;
  for(int i=n-1; i>0; i--)
    if(s[i] > s[i-1]) {
      pos=i-1;
      break;
    }
  if(pos != -1) {
    for(int i=n-1; i>pos; i--) {
      if(s[pos] < s[i]) {
        swap(s[pos], s[i]);
        for(int j=0; j<(n-pos-1)/2; j++) {
          cout << s[j+pos+1] << " " << s[n-1-j] << "\n";
          swap(s[j+pos+1], s[n-j-1]);
        }
        break;
      }
    }
    cout << s << "\n";
  } else {
    cout << "Next Permutation is not avaliable\n";
  }
}

int32_t main() {
	tool();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
