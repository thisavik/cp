#include <iostream>
#include <vector>
#include <algorithm>

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

void solve();
void solve(int, int);

vector<int> tree[maxN];
int dp[maxN][2];

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    solve(1, -1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

void solve(int s, int par)
{
    vector<int> prefix, suffix;
    dp[s][0] = dp[s][1] = 0;
    bool leaf = 1;
    for (int child : tree[s])
    {
        if (child != par)
        {
            leaf = 0;
            solve(child, s);
        }
    }
    if (leaf)
        return;
    for (int child : tree[s])
    {
        if (child != par)
        {
            prefix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }
    for (int i = 1; i < prefix.size(); i++)
        prefix[i] += prefix[i - 1];
    for (int i = suffix.size() - 2; i >= 0; i--)
        suffix[i] += suffix[i + 1];
    // option-1 left the node and take solution from all child
    dp[s][0] = suffix[0];
    int cnt_no = 0;
    // another option select an edge (u -> v) and check from which edge we will get maximum
    for (int child : tree[s])
    {
        if(child != par)
        {
            // calculate answer from left child i.e (1 to cnt_no-1)
            int leftChildren = cnt_no == 0 ? 0 : prefix[cnt_no-1];
            // calculate answer from right child i.e (cnt_no+1 to kth)
            int rightChildren = cnt_no+1 == suffix.size() ? 0 : suffix[cnt_no+1];
            // took maximum of all 
            dp[s][1] = max(dp[s][1], leftChildren + 1 + dp[child][0] + rightChildren);
            cnt_no++;
        }
    }
}