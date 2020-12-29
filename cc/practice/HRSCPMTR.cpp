#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)

bool helper(vector<int> &temp)
{
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] != temp[i - 1])
        {
            return false;
            break;
        }
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    vector<int> temp;
    int cnt = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> arr[i][j];
        }
    }
    for (int k = n - 1; k > 0; k--)
    {
        for (int i = k, j = 0; i < n; i++, j++)
        {
            temp.push_back(arr[i][j]);
        }
        cnt += (temp.size() == 1 ? 0 : helper(temp));
        temp.clear();
    }
    
    for (int k = 0; k < m; k++)
    {
        for (int i = 0, j = k; j < m && i < n; i++, j++)
        {
            temp.push_back(arr[i][j]);
        }
        cnt += (temp.size() == 1 ? 0 : helper(temp));
        temp.clear();
    }
    int q, x, y, v;
    cin >> q;
    rep(k, q)
    {
        cin >> x >> y >> v;
        x--, y--;
        for(int i = x, j = y; i < n && j < m; i++, j++)
            temp.push_back(arr[x][y]);
        for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
            temp.push_back(arr[i][j]);
        if(helper(temp))
            cnt--;
        temp.clear();
        arr[x][y] = v;
        for(int i = x, j = y; i < n && j < m; i++, j++)
            temp.push_back(arr[i][j]);
        for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
            temp.push_back(arr[i][j]);
        if(helper(temp))
            cnt++;
        temp.clear();
        if(cnt == n+m-3)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}