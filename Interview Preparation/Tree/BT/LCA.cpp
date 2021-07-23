// finding lowest common ancestor

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode *LCA(TreeNode*, int, int);
void dfs(TreeNode*, int, unordered_map<int, pair<TreeNode*, int>>&);
TreeNode* lca(TreeNode*, int, int);

int32_t main()
{
    tool();
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);

    cout << LCA(root, 20, 50)->data << "\n";
    cout << lca(root, 20, 50)->data;
}

TreeNode *LCA(TreeNode *root, int n1, int n2)
{
    if (!root)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    TreeNode *left = LCA(root->left, n1, n2);
    TreeNode *right = LCA(root->right, n1, n2);

    // case when one node is in left subtree and another is in right subtree 
    if (left != nullptr && right != nullptr)
        return root;

    if (left != nullptr)
        return left;
    else
        return right;
}

// convert tree to parent array
void dfs(TreeNode *root, int p, unordered_map<int, pair<TreeNode*, int>>& par)
{
    if(root == nullptr)
        return;
    par[root->data].first = root;
    par[root->data].second = p;
    dfs(root->left, root->data, par);
    dfs(root->right, root->data, par);
}

TreeNode* lca(TreeNode *root, int n1, int n2)
{
    unordered_map<int, pair<TreeNode*, int>> par;
    dfs(root, -1, par);
    unordered_map<int, bool> vis;
    while(par[n1].second != -1)
        vis[n1] = true, n1 = par[n1].second;
    vis[n1] = true;
    while(!vis[n2])
        n2 = par[n2].second;
    return par[n2].first;
}