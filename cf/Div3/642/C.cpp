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
    int n, ans=0;
    cin >> n;
    int i = n/2;
    int x = 2*n + 2*(n-2);
    for(int i=n/2; i>0; i--) {
      ans += x*i;
      x-=8;
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
