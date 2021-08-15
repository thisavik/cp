/*
 *  author: thisavik
 *  created: 19:33:38 15-08-2021 Sun
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/thisa/OneDrive/Documents/cp/input.txt", "r", stdin);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/output.txt", "w", stdout);
    freopen("C:/Users/thisa/OneDrive/Documents/cp/error.txt", "w", stderr);
#endif
}

class Solution
{
    struct TrieNode
    {
        TrieNode *next[2];
        TrieNode()
        {
            next[0] = next[1] = NULL;
        }
    };
    TrieNode *root;
    void insert(int n)
    {
        TrieNode *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int b = (n >> i) & 1;
            if (!curr->next[b])
                curr->next[b] = new TrieNode();
            curr = curr->next[b];
        }
    }
public:
    Solution()
    {
        root = new TrieNode();
    }
    static bool comp(vector<int> &a1, vector<int> &a2)
    {
        return a1[1] < a2[1];
    }
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int q = queries.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < q; i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), comp);
        int idx, x, m, s = 0, e = 0;
        vector<int> ans(q);
        for (int i = 0; i < q; i++)
        {
            TrieNode *curr = root;
            x = queries[i][0], m = queries[i][1], idx = queries[i][2];
            e = lower_bound(nums.begin(), nums.end(), m) - nums.begin();
            if (e == nums.size() || nums[e] > m)
                e--;
            if (e < 0)
            {
                ans[idx] = -1;
                continue;
            }
            for (int j = s; j <= e; j++)
                insert(nums[j]);
            s = e + 1;
            int _xor = 0;
            for (int j = 31; j >= 0; j--)
            {
                int b = (x >> j) & 1;
                if (curr->next[b ^ 1])
                    _xor += (1 << j), curr = curr->next[b ^ 1];
                else if (curr->next[b])
                    curr = curr->next[b];
                else
                    break;
            }
            ans[idx] = _xor;
        }

        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &val: a)
        cin >> val;
    int q;
    cin >> q;
    vector<vector<int>> queries(q);
    int x, m;
    for(auto &query: queries)
        cin >> x >> m, query.push_back(x), query.push_back(m);
    Solution s;
    vector<int> ans = s.maximizeXor(a, queries);
    for(int i = 0; i < ans.size(); i++)
        cout << i << " : " << ans[i] << " \n"[i == ans.size()];
}

int32_t main(int32_t argc, char *args[])
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}