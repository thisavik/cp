/*
 *  author: thisavik
 *  created: 20:43:48 01-08-2021 Sun
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

void tool()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
  int n, m, x, y, q;
  cin >> n >> m;
  vector<int> adj[n+1];
  for(int i = 0; i < m; i++)
  {
    cin >> x >> y;
    if(x > y)
      swap(x, y);
    adj[x].push_back(y);
  }
  int killed = 0;
  for(int i = 1; i <= n; i++)
  {
    if(adj[i].size() != 0)
      killed++;
  }
  cin >> q;
  for(int i = 0; i < q; i++)
  {
    int qType, x, y;
    cin >> qType;
    if(qType == 3) 
    {
      cout << n - killed << "\n";
    }
    else
    {
      cin >> x >> y;
      if(qType == 1)
      {
        if(x > y)
          swap(x, y);
        adj[x].push_back(y);
        if(adj[x].size() == 1)
          killed++;
      }
      else
      {
        for(auto &val: adj[x])
        {
          if(val == y)
          {
            val = adj[x].back();
            adj[x].pop_back();
            if(adj[x].size() == 0)
              killed--;
            break;
          }
        }
        for(auto &val: adj[y])
        {
          if(val == x)
          {
            val = adj[y].back();
            adj[y].pop_back();
            if(adj[x].size() == 0)
              killed--;
            break;
          }
        }
      }
    }
  }
}

int32_t main(int32_t argc, char *args[])
{
  tool();
  int t = 1;
  // cin >> t;
  while(t--)
    solve(); 
  return 0;
}