// working on adjacency list of tree
// finding lowest common ancestor

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
const int maxN = 1e1;

// for creating graph
vector<int> adj[N];

// level contains level of each node
int level[N];

// dp[i][j] contain ancestor of i at 2^j distance
int dp[N][maxN];

void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    dp[node][0] = par;
    for (int child : adj[node])
        if (child != par)
            dfs(child, lvl + 1, node);
}

void init(int n)
{
    dfs(1, 0, -1);
    for (int j = 1; j < maxN; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dp[i][j - 1] != -1)
            {
                int par = dp[i][j - 1];
                dp[i][j] = dp[par][j - 1];
            }
        }
    }
}

int getLCA(int a, int b)
{
    if (level[b] < level[a])
        swap(b, a);

    int d = level[b] - level[a];
    while (d > 0)
    {
        int i = (int)log2(d);
        b = dp[b][i];
        d -= (1 << i);
    }
    if (a == b)
        return a;

    for (int i = maxN - 1; i >= 0; i--)
    {
        if (dp[a][i] != -1 && (dp[a][i] != dp[b][i]))
            a = dp[a][i], b = dp[b][i];
    }
    return dp[a][0];
}

int32_t main()
{
    int n, a, b;
    cin >> n;

    memset(dp, -1, sizeof(-1));
    // n node -> n-1 edeges in case of tree
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(n);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < maxN; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    
    /*int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << getLCA(a, b) << "\n";
    }*/
}