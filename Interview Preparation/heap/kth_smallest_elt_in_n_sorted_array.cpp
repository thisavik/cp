#include <bits/stdc++.h>

using namespace std;

void tool() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct T
{
    int val, x, y;
};

struct comp
{
    bool operator()(T &t1, T &t2)
    {
        return t1.val > t2.val;
    }
};

int solve(vector<vector<int>> &mat, int k)
{
    int n1 = mat.size();

    // we will insert {data from array 1, data from array 2, position of data 2 form array 1}
    priority_queue<T, vector<T>, comp> pq;

    for(int i = 0; i < n1; i++)
        pq.push({mat[i][0], i, 0});
    T ans;
    while(k > 0)
    {
        ans = pq.top(); pq.pop(); k--;
        if(ans.y+1 == mat[ans.x].size())
            continue;
        pq.push({mat[ans.x][ans.y+1], ans.x, ans.y+1});
    }
    return ans.val;
}

int32_t main()
{
    tool();
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    for(auto&v : mat)
        for(int& val : v)
            cin >> val;
    cout << solve(mat, k) << "\n";
    return 0;
}