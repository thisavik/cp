// finding diameter of binary tree

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("C://git//cp//input.txt", "r", stdin);
    freopen("C://git//cp//output.txt", "w", stdout);
#endif
}

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};


int heightWithDiameter(TreeNode *, int &);
pair<int, int> heightWithDiameter(TreeNode*);
int height(TreeNode *);
int diameter(TreeNode *);

int32_t main()
{
    tool();
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    int res = 0;
    heightWithDiameter(root, res);
    cout << res << "\n";
    cout << diameter(root) << "\n";
    cout << heightWithDiameter(root).second << "\n";
}



// this code took O(n^2) time to process but
// we can optimize this using dynamic programming 
// but storing height as preprocessing

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max({ld, rd, 1 + lh + rh});
}

// one more way to solve this is return height and diamter both 
// at the time of calling each node
pair<int, int> heightWithDiameter(TreeNode* root)
{
    if(root == nullptr)
        return {0, 0};
    
    auto lo = heightWithDiameter(root->left);
    auto ro = heightWithDiameter(root->right);

    int height = 1 + max(lo.first, ro.first);
    int op1 = 1 + lo.first + ro.first;
    int op2 = lo.second;
    int op3 = ro.first;
    int diameter = max({op1, op2, op3});
    return {height, diameter};
}

// took O(n) time
int heightWithDiameter(TreeNode *root, int &res)
{
    if (root == nullptr)
        return 0;
    int lh = heightWithDiameter(root->left, res);
    int rh = heightWithDiameter(root->right, res);
    res = max(res, 1 + lh + rh);

    return 1 + max(lh, rh);
}