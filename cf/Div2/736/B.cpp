    /*
     *  author: thisavik
     *  created: 20:16:27 01-08-2021 Sun
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
      int n;
      cin >> n;
      string enemy, nth;
      cin >> enemy;
      cin >> nth;
      int ans = 0;
      for(int i = 0; i < n; i++) 
      {
        if(nth[i] == '1')
        {
          if(enemy[i] == '0')
            ans++;
          else 
          {
            if(i > 0 && enemy[i-1] == '1')
              ans++, enemy[i-1] = '0';
            else if(i < n-1 && enemy[i+1] == '1')
              ans++, enemy[i+1] = '0';
          }
        }  
      }
      cout << ans << "\n";
    }
    
    int32_t main(int32_t argc, char *args[])
    {
      tool();
      int t;
      cin >> t;
      while(t--)
        solve(); 
      return 0;
    }