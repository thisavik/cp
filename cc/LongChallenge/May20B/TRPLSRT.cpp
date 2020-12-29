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
  int n, k, x;
  cin >> n >> k;
  vi a(n+1), pos(n+1);
  Fori(i, 1, n+1) {
    cin >> a[i];
    pos[a[i]]=i;
  }
  vi temp;
  vector<bool> vis(n+1, false);
  vii arr, ans;
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
  // Fori(i, 0, arr.size()) {
  //   Forj(j, 0, arr[i].size())
  //     cout << arr[i][j] << " ";
  //   cout << "\n";
  // }
  temp.clear();
  Fori(i, 0, arr.size()) {
    x = arr[i].size();
    while(x > 2) {
      temp.push_back(pos[arr[i][x-1]]);
      temp.push_back(pos[arr[i][x-2]]);
      temp.push_back(pos[arr[i][x-3]]);
      pos[arr[i][x-1]]= pos[arr[i][x-3]];
      swap(arr[i][x-3], arr[i][x-1]);
      vi::it itr = arr[i].end();
      itr--; itr--;
      arr[i].erase(itr, arr[i].end());
      x-=2;
      reverse(temp.begin(), temp.end());
      ans.push_back(temp);
      temp.clear();
    }
  }
  // Fori(i, 0, arr.size()) {
  //   cout << arr[i].size() << " ";
  // }
  // cout << "\n";
  a.clear();
  Fori(i, 0, arr.size()) {
    if(arr[i].size() == 2) {
      a.push_back(arr[i][0]);
      a.push_back(arr[i][1]);
    }
  }
  temp.clear();
  if(a.size()%4 == 0) {
    x=a.size();
    while(x > 0) {
      temp.push_back(pos[a[x-3]]);
      temp.push_back(pos[a[x-2]]);
      temp.push_back(pos[a[x-4]]);
      reverse(temp.begin(), temp.end());
      ans.push_back(temp);
      temp.clear();
      temp.push_back(pos[a[x-2]]);
      temp.push_back(pos[a[x-1]]);
      temp.push_back(pos[a[x-3]]);
      reverse(temp.begin(), temp.end());
      ans.push_back(temp);
      temp.clear();
      a.resize(a.size()-4);
      x = a.size();
    }
  } else {
    cout << -1 << "\n";
    return;
  }
  if(a.size() == 0) {
    cout << ans.size() << "\n";
    Fori(i, 0, ans.size()) {
      Forj(j, 0, ans[i].size())
        cout << ans[i][j] << " ";
      cout << "\n";
    }
  } else {
    cout << -1 << "\n";
    return;
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
