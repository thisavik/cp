// working on adjacency list of tree
// finding lowest common ancestor

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int N = (int)1e3 + 1;
const int maxN = (int)1e1;
// for creating graph
vector<int> adj[N];
int level[N], LCA[N][maxN];

void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    LCA[node][0] = par;
    for (int child : adj[node])
        // ensure we don't make recursive call to parent
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
            if (LCA[i][j - 1] != -1)
            {
                int par = LCA[i][j - 1];
                LCA[i][j] = LCA[par][j - 1];
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
        b = LCA[b][i];
        d -= (1 << i);
    }
    if (a == b)
        return a;

    for (int i = maxN - 1; i >= 0; i--)
    {
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
            a = LCA[a][i], b = LCA[b][i];
    }
    return LCA[a][0];
}

int32_t main()
{
    tool();
    int n, a, b;
    cin >> n;

    memset(LCA, -1, sizeof(-1));
    // n node -> n-1 edeges in case of tree
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << getLCA(a, b) << "\n";
    }
}