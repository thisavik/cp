#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)

int calculate(vector<int> &v)
{
    int ans = 0;
    sort(v.begin(), v.end());
    int median = v[v.size()/2];
    for(int val: v)
        ans += abs(median-val);
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        rep(i, n)
        {
            rep(j, m)
            {
                cin >> mat[i][j];
            }
        }
        int ans = 0;
        rep(i, (n+1)/2)
        {
            rep(j, (m+1)/2)
            {
                vector<int> v;
                v.push_back(mat[i][j]);
                if(j != m-j-1)
                    v.push_back(mat[i][m-j-1]);
                if(i != n-i-1)
                    v.push_back(mat[n-i-1][j]);
                if(i != n-i-1 && j != m-j-1)
                    v.push_back(mat[n-i-1][m-j-1]);
                ans += calculate(v);
            }
        }
        cout << ans << "\n";
    }
}