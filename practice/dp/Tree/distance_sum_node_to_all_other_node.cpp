#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i <= b; i++)
#define int long long

const int mxN = 2 * 1e5 + 1;

vector<int> g[mxN];
int n, in[mxN], out[mxN], childIn[mxN];

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C://git//cp//input.txt", "r", stdin);
	freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

void dfs1(int src = 1, int par = 0)
{
    childIn[src] = 0;
    for (int child : g[src])
    {
        if (child == par)
            continue;
        dfs1(child, src);
        childIn[src] += childIn[child] + 1;
    }
}

void dfs2(int src = 1, int par = 0)
{
    in[src] = 0;
    for (int child : g[src])
    {
        if (child == par)
            continue;
        dfs2(child, src);
        in[src] += 1 + in[child] + childIn[child];
    }
}

void dfs3(int src = 1, int par = 0)
{
    for (int child : g[src])
    {
        if (child == par)
            continue;
        out[child] = (n - childIn[child]-1) + out[src] + (in[src]-in[child]-childIn[child]-1);
        dfs3(child, src);
    }
}

int32_t main()
{
    tool();
    int u, v;
    cin >> n;
    rep(i, n-1) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    dfs1();
    dfs2();
    dfs3();
    range(i, 1, n) cout << childIn[i] << " ";
    cout << "\n";
    range(i, 1, n) cout << in[i] << " ";
    cout << "\n";
    range(i, 1, n) cout << out[i] << " ";
    cout << "\n";
    range(i, 1, n) cout << in[i]+out[i] << " ";
    return 0;
}

/*
12 5 5 2 1 2 1 0 0 0 0 0 0 
28 8 8 2 1 2 1 0 0 0 0 0 0 
0 21 21 27 30 27 30 30 30 31 30 30 31 
28 29 29 29 31 29 31 30 30 31 30 30 31 
*/