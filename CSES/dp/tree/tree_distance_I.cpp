#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define maxN (int)1e5 * 2 + 1

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

int n;
vector<int> tree[maxN];
int depth[maxN], ans[maxN];

void printTree()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for (int child : tree[i])
            cout << child << " ";
        cout << "\n";
    }
    cout << "\n";
}

void evalDepth(int s, int par)
{
    int sDepth = 0;
    for (int child : tree[s])
        if (child != par)
        {
            evalDepth(child, s);
            sDepth = max(sDepth, 1 + depth[child]);
        }
    depth[s] = sDepth;
}

void solve(int src, int par, int par_ans)
{
    vector<int> prefixMax, suffixMax;
    // get depth of child nodes.
    for (int child : tree[src])
    {
        if (child != par)
        {
            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }
    // build prefix and suffix
    for (int i = 1; i < prefixMax.size(); i++)
        prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);
    for (int i = (int)suffixMax.size() - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i], suffixMax[i + 1]);

    //eval ans for every child c_no
    int c_no = 0;
    for (int child : tree[src])
    {
        if (child != par)
        {
            int op1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
            int op2 = (c_no == (int)suffixMax.size() - 1) ? INT_MIN : suffixMax[c_no + 1];
            int partial_ans = 1 + max(par_ans, max(op1, op2));

            solve(child, src, partial_ans);
            c_no++;
        }
    }

    //eval ans for src
    ans[src] = 1 + max(par_ans, (prefixMax.empty() ? -1 : prefixMax.back()));
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    // assuming 1 as root
    evalDepth(1, 0);
    solve(1, 0, -1);
    for (int i = 1; i <= n; i++)
        cout << i << " " << ans[i] << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}