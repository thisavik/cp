// farthest node from a given leaf

#include <iostream>
#include <vector>

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

int minTimeToBurn(TreeNode *, int);
int minTimeToBurn(TreeNode *, int, int &, int &);

int32_t main()
{
    tool();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << minTimeToBurn(root, 9);
}

int minTimeToBurn(TreeNode *root, int leaf)
{
    int dist = -1, res = 0;
    minTimeToBurn(root, leaf, dist, res);
    return res;
}

int minTimeToBurn(TreeNode *root, int leaf, int &dist, int &res)
{
    if (root == nullptr)
        return 0;
    if (root->data == leaf)
    {
        dist = 0;
        return 1;
    }
    // keep track of node which are ancestor of leaf node
    int ldist = -1, rdist = -1;
    int lh = minTimeToBurn(root->left, leaf, ldist, res);
    int rh = minTimeToBurn(root->right, leaf, rdist, res);
    cout << root->data << " -> " << ldist << " " << rdist << " " << lh << " " << rh << "\n";
    if (ldist != -1)
    {
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    if (rdist != -1)
    {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }
    cout << res << "\n";
    return 1 + max(lh, rh);
}