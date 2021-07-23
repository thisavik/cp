#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = left;
    }
};

int hgt(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(hgt(root->left), hgt(root->right));
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return (abs(hgt(root->left) - hgt(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

int32_t main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    // root->left->left->left = new TreeNode(4);
    // root->left->left->right = new TreeNode(4);
    cout << boolalpha << isBalanced(root);
}