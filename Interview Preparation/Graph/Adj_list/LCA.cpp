#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define range(i, a, b) for(int i = a; i <= b; i++)
#define range2(i, a, b) for(int i = a; i >= b; i--)

const int mxN = 1e5+1;
const int mxLN = log2(mxN);
int n, ln;
vector<int> tree[mxN];
int level[mxN] = {0};
int dp[mxN][mxLN];

void dfs(int s, int p)
{
    level[s] = level[p] + 1;
    dp[s][0] = p;
    range(i, 1, ln)
    {
        dp[s][i] = dp[dp[s][i-1]][i-1];
    }
    for(int child: tree[s])
    {
        if(child != p)
            dfs(child, s);
    }
}

int getLCA(int a, int b)
{
    if(level[b] < level[a])
        swap(a, b);
    int diff = level[b] - level[a];
    rep(i, ln)
    {
        if((1 << i) & diff)
            b = dp[b][i];
    }
    if(a == b)
        return a;
    range2(i, ln-1, 0)
    {
        if(dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int32_t main()
{
    cin >> n;
    ln = log2(n)+1;
    rep(i, n-1)
    {
        int u, v;
        cin >> u >> v, tree[u].push_back(v), tree[v].push_back(u);
    }
    dfs(1, 0);
    cout << getLCA(1, 7) << "\n";
    cout << getLCA(2, 5) << "\n";
    cout << getLCA(3, 4);
}