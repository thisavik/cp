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

int32_t main()
{
  tool();
  int t;
  cin >> t;
  string temp = "codeforces";
  vi a(10, 1);
  int mul = 1;
  if(t==mul) {
    cout << temp;
    return 0;
  }
  int i = 0;
  while(i<10) {
    a[i]++;
    mul=1;
    for(int j=0; j<10; j++)
      mul*=a[j];
    if(mul >= t) {
      break;
    }
    if(i == 9)
      i=0;
    else
      i++;
  }
  // for(int& val: a)
  //   cout << val << " ";
  string s = "";
  for(int i=0; i<10; i++) {
    for(int j=0; j<a[i]; j++)
      s += temp[i];
  }
  cout << s << " ";
  return 0;
}