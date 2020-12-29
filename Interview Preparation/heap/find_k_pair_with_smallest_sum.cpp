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
    int x, y, pos;
};

struct comp
{
    bool operator()(T &t1, T &t2)
    {
        return t1.x + t1.y > t2.x + t2.y;
    }
};

vector<vector<int>> solve(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size(), n2 = b.size();
    vector<vector<int>> ans;
    if(n1 == 0 || n2 == 0)
        return ans;

    // we will insert {data from array 1, data from array 2, position of data 2 form array 1}
    priority_queue<T, vector<T>, comp> pq;

    for(int i = 0; i < n1; i++)
        pq.push({a[i], b[0], 0});

    while(k > 0 && !pq.empty())
    {
        auto t = pq.top(); pq.pop();
        ans.push_back(vector<int>({t.x, t.y})); k--;
        if(t.pos+1 == n2)
            continue;
        pq.push({t.x, b[t.pos+1], t.pos+1});
    }
    return ans;
}

int32_t main()
{
    tool();
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int&val : a)
        cin >> val;
    vector<int> b(m);
    for(int& val : b)
        cin >> val;
    vector<vector<int>> ans = move(solve(a, b, k));
    for(auto& v : ans)
    {
        for(auto& val : v)
            cout << val << " ";
        cout << "\n";
    }
    return 0;
}