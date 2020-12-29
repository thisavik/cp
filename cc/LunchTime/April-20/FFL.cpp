#include <bits/stdc++.h>
using namespace std;
void tool()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("C:\\git\\cp\\input.txt", "r", stdin);
  freopen("C:\\git\\cp\\output.txt", "w", stdout);
#endif
}
int32_t main() {
  tool();
  int t;
  cin >> t;
  while(t--) {
    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i=0; i<n; i++)
      cin >> a[i];
    int mind=101, minf=101, x;
    for(int i=0; i<n; i++) {
      cin >> x;
      if(x==0)
        mind = min(mind, a[i]);
      else 
        minf = min(minf, a[i]);
    }
    s = s+mind+minf;
    if(s<=100)
      cout << "yes\n";
    else 
      cout << "no\n";
  }
}