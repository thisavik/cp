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

const int maxN = 2*1e5+1;

vector<int> tree[maxN];
int in[maxN], out[maxN];

// for calculating in[] array
// in array represent height of tree when parent node is not in path
void dfs1(int s, int par)
{
    in[s] = 0;
    int mx = 0;
    for(int child : tree[s])
    {
        if(child != par)
        {
            dfs1(child, s);
            in[s] = max(in[s], 1 + in[child]);
        }
    }
}

// for calculating in[] array
// out array represent height of tree when parent is in path
void dfs2(int s, int par)
{
    int mx1 = -1, mx2 = -1;
    for(int child : tree[s])
    {
        if(child != par)
        {
            if(in[child] >= mx1)
                mx2 = mx1, mx1 = in[child];
            else if(in[child] > mx2)
                mx2 = in[child];
        }
    }

    for(int child : tree[s])
    {
        if(child != par)
        {
            int mx = mx1;
            if(in[child] == mx1)
                mx = mx2;
            out[child] = 1 + max(out[s], 1 + mx);
            dfs2(child, s);
        }
    }
}

int32_t main()
{
    tool();
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, max(in[i], out[i]));
    cout << ans;
}