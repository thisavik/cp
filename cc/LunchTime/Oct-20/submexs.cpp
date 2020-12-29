#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 + 1;

vector<int> tree[mxN];

// efficient way to do this in one dfs
// first store max sum of count subtrees in path from node to leaf
// second store subtree size of a particular node
pair<int64_t, int> dfs(int s)
{
    int64_t mx = 0;
    int sz = 1;
    for (int child : tree[s])
    {
        auto temp = dfs(child);
        mx = max(mx, temp.first);
        sz += temp.second;
    }
    return {mx + sz, sz};
}

void clear()
{
    for(auto &v: tree)
        v.clear();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        clear();
        for (int i = 2; i <= n; i++)
            cin >> x, tree[x].push_back(i);
        cout << dfs(1).first << "\n";
    }
}
/*
2
3
1 1
5
1 1 2 2
*/