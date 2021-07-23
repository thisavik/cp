#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    char ch;
    vector<TrieNode *> adj;
    int end;
    string word;
    TrieNode(char ch)
    {
        this->ch = ch;
        adj = vector<TrieNode *>(26, nullptr);
        end = 0;
        word = "";
    }
};

struct Trie
{
    TrieNode *root;
    Trie() : root(new TrieNode('/')) {}
    void insert(string s)
    {
        int idx;
        TrieNode *cur = root;
        for (auto ch : s)
        {
            idx = ch - 'a';
            if (cur->adj[idx] == nullptr)
                cur->adj[idx] = new TrieNode(ch);
            cur = cur->adj[idx];
        }
        cur->end++;
        cur->word = s;
    }
    string solve()
    {
        TrieNode *cur = root;
        string res = "";
        bool flag;
        do
        {
            flag = false;
            for (int i = 0; i < 26; i++)
                if (cur->adj[i]) {
                    res += i + 'a';
                    cur = cur->adj[i];
                    flag = true;
                    break;
                }
                
        } while(flag);
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (auto &word : words)
        cin >> word;
    Trie t;
    for (auto s : words)
        t.insert(s);
    cout << t.solve() << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}