#include <iostream>
#include <vector>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

const int maxN = 2 * 1e5 + 1;

vector<int> tree[maxN];
int in[maxN], out[maxN];

// for calculating in[] array
// in array represent height of tree when parent node is not in path
void dfs1(int s = 1, int par = 0)
{
    in[s] = 0;
    int mx = 0;
    for (int child : tree[s])
    {
        if (child != par)
        {
            dfs1(child, s);
            mx = max(mx, in[child]);
        }
    }
    in[s] = 1 + mx;
}

// for calculating out[] array
// out array represent height of tree when parent is in path
void dfs2(int s = 1, int par = 0)
{
    int mx1 = -1, mx2 = -1;
    for (int child : tree[s])
    {
        if (child != par)
        {
            if (in[child] >= mx1)
                mx2 = mx1, mx1 = in[child];
            else if (in[child] > mx2)
                mx2 = in[child];
        }
    }
    for (int child : tree[s])
    {
        if (child != par)
        {
            int mx = mx1;
            if (in[child] == mx1)
                mx = mx2;
            out[child] = 1 + max(out[s], 1 + mx);
            dfs2(child, s);
        }
    }
}

void printTree(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (int j : tree[i])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

int32_t main()
{
    tool();
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    // printTree(n);
    dfs1();
    dfs2();
    for (int i = 1; i <= n; i++)
        cout << i << " -> " << max(in[i], out[i]) << "\n";
}