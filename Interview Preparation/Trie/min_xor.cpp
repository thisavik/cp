/*
 *  author: thisavik
 *  created: 12:44:34 15-08-2021 Sun
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

struct Trie
{
    struct TrieNode
    {
        TrieNode *left;
        TrieNode *right;
        TrieNode *next[2];
        TrieNode() : left(NULL), right(NULL)
        {
            next[0] = NULL, next[1] = NULL;
        }
    };
    TrieNode *head;
    Trie()
    {
        head = new TrieNode(); 
    }
    void insert(int n)
    {
        TrieNode *curr = head;
        for(int i = 31; i >= 0; i--)
        {
            int b = (n >> i) & 1;
            if(!curr->next[b])
                curr->next[b] = new TrieNode();
            curr = curr->next[b];
        }
    }
    int findMinXorPair(vector<int> &a)
    {
        int max_xor = INT_MAX;
        for(int i = 1; i < a.size(); i++)
        {
            TrieNode *curr = head;
            int n = a[i];
            int curr_xor = 0;
            for(int j = 31; j >= 0; j--)
            {
                int b = (n >> j) & 1;
                if(curr->next[b])
                {
                    curr = curr->next[b];
                }
                else if(curr->next[b^1])
                {
                    curr_xor += (1 << j);
                    curr = curr->next[b^1];
                } 
                else
                    break;
            }
            insert(n);
            cout << curr_xor << "\n";
            max_xor = min(max_xor, curr_xor);
        }
        return max_xor;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &val: a)
        cin >> val;
    Trie t;
    t.insert(a[0]);
    cout << t.findMinXorPair(a) << "\n";
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