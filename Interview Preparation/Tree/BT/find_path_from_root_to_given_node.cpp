// finding lowest common ancestor

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool findPath(TreeNode *root, vector<TreeNode *> &path, int n)
{
    if (root == nullptr)
        return false;
    path.push_back(root);

    if (root->data == n || findPath(root->left, path, n) || findPath(root->right, path, n))
        return true;

    path.pop_back();
    return false;
}

int32_t main()
{
    tool();
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);

    vector<TreeNode *> path;
    if (findPath(root, path, 50))
        for (auto u : path)
            cout << u->data << " ";
    else
        cout << -1 << " ";
    return 0;
}