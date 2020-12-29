#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define ff first
#define ss second
#define MOD (int)10e9 + 7
#define endl "\n"
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define si set<int>
#define mii map<int, int>
#define Fori(i, a, n) for (int i = a; i < n; i++)
#define Forj(j, a, n) for (int j = a; j < n; j++)
#define Fork(k, a, n) for (int k = a; k < n; k++)
void tool()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("C://git//cp//input.txt", "r", stdin);
  freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

void solveUsingPreSuf();

void solve()
{
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vi a;
  Fori(i, 0, n)
    if(s[i] == '1') {
      a.push_back(i);
    }
  int ans = 0;
  if(a.size() == 0) {
    for(int i=0; i<n; i+=(k+1))
        ans++;
    cout << ans << "\n";
    return;
  }
    for(int i = a[0]-(k+1); i >= 0; i-=(k+1))
        ans++;
  for(int i=1; i<a.size(); i++) {
        for(int j = a[i]-(k+1); j >= (a[i-1]+(k+1)); j-=(k+1))
            ans++;      
  }
    for(int i = a[a.size()-1]+(k+1); i < n; i+=(k+1))
        ans++;
  cout << ans << "\n";
}
int32_t main()
{
  tool();
  int t;
  cin >> t;
  while (t--) {
    // solve();
    solveUsingPreSuf();
  }
  return 0;
}


// using suffix-prefix array

// in prefix at index(i) we will store the index of closest one from i from left
// similarly in suffix array at index(i) we will store the index of closest one from right

// string s = "100001001"
// pre = [0, 0, 0, 0, 0, 5, 5, 5, 8]
// suf = [0, 5, 5, 5, 5, 5, 8, 8, 8]

// Now, we have to only check whether placing 1 is valid on ani index(i) in string or not using 
// this two array 

void solveUsingPreSuf() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vi pre(n+2, -1), suf(n+2, -1);  // -1 for indicate we haven't encounter and 1 till that index

  if(s[0] == '1')
    pre[0] = 0;

  if(s[n-1] == '1')
    suf[n-1] = n-1;

  for(int i=1; i<n; i++)
    if(s[i] == '1')
      pre[i] = i;
    else
      pre[i] = pre[i-1];
  for(int i=n-2; i>=0; i--)
    if(s[i] == '1')
      suf[i] = i;
    else
      suf[i] = suf[i+1];
  
  int ans = 0;
  for(int i=0; i<n; i++) {
    int v1, v2;
    v1 = v2 = INT_MAX; // when both pre[i] and suf[i] has -1 then we can put 1 there. Think ?
    if(pre[i]!=-1) {
      v1 = i-pre[i];
    }
    if(suf[i]!=-1) {
      v2 = suf[i]-i;
    }
    if(min(v1, v2) > k) {
      ans++;
      pre[i]=i;
    }
    if(pre[i+1] < pre[i]) {
      pre[i+1]=pre[i];
    }
  }
  cout << ans << "\n";
}