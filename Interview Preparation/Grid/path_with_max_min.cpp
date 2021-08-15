/*
 *  author: thisavik
 *  created: 13:57:48 11-08-2021 Wed
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/thisa/OneDrive/Documents/cp/input.txt", "r", stdin);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/output.txt", "w", stdout);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/error.txt", "w", stderr);
#endif
}

struct T
{
    int val, x, y;
};

struct comp
{
    bool operator()(T &a, T &b)
    {
        return a.val < b.val;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> mat[i][j];
        }
    }
    priority_queue<T, vector<T>, comp> pq;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0)); 
    pq.push({mat[0][0], 0, 0});
    vis[0][0] = 1;
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if(cur.x == n-1 && cur.y == m-1)
        {
            cout << cur.val << "\n";
            return;
        }
        rep(i, 0, 4)
        {
            int xNew = cur.x + dx[i];
            int yNew = cur.y + dy[i];
            if(xNew >= 0 && xNew < n && yNew >= 0 && yNew < m && !vis[xNew][yNew])
            {
                vis[xNew][yNew] = 1;
                // cout << xNew << " " << yNew << "\n";
                pq.push({min(cur.val, mat[xNew][yNew]), xNew, yNew});
            }
        }
    }
    cout << -1 << "\n";
}

int32_t main(int32_t argc, char *args[])
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
2 6
2 2 1 2 2 2 
1 2 2 2 1 2
6 5
3 4 6 3 4
0 2 1 1 7
8 8 3 2 7
3 2 4 9 8
4 1 2 0 0 
4 6 5 4 3
*/