#include <iostream>
#include <vector>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// An AVL Tree Node
class TreeNode
{
public:
    int data, height;
    TreeNode *left, *right;
    TreeNode(int key)
    {
        data = key;
        left = right = nullptr;
        height = 1;
    }
};

// return height of node
int height(TreeNode *root)
{
    if (!root)
        return 0;
    return root->height;
}

// check balance factor of the node
int getBalance(TreeNode *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

// Left Left rotation
TreeNode *rightRotate(TreeNode *root)
{
    TreeNode *rootL = root->left;
    TreeNode *rootLR = rootL->right;

    // rotation
    rootL->right = root;
    root->left = rootLR;

    // height update
    root->height = 1 + max(height(root->left), height(root->right));
    rootL->height = 1 + max(height(rootL->left), height(rootL->right));

    return rootL;
}

// Right Right Rotation
TreeNode *leftRotate(TreeNode *root)
{
    TreeNode *rootR = root->right;
    TreeNode *rootRL = rootR->left;

    // rotation
    rootR->left = root;
    root->right = rootRL;

    // height update
    root->height = 1 + max(height(root->left), height(root->right));
    rootR->height = 1 + max(height(rootR->left), height(rootR->right));

    return rootR;
}

// Recursive insert in BST
TreeNode *insertNode(TreeNode *root, int data)
{
    // if root is null
    if (!root)
        return new TreeNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else
        return root; // equal key are not allowed in bst

    root->height = 1 + max(height(root->left), height(root->right));

    int br = getBalance(root);

    // 4 cases of unbalance
    // Left Left Case
    if (br > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    // Right Right Case
    else if (br < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }
    // Left Right Case
    else if (br > 1 && data > root->left->data)
    {
        // double rotation
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    else if (br < -1 && data < root->right->data)
    {
        // double rotation
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // return the unchanged TreeNode pointer if everything is valid
    return root;
}

TreeNode *minValueNode(TreeNode *root)
{
    TreeNode *cur = root;
    while (root && root->left)
        root = root->left;
    return root;
}

// Recursive delete in BST
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == nullptr)
        {
            TreeNode *rootR = root->right;
            free(root);
            return rootR;
        }
        else if (root->right == nullptr)
        {
            TreeNode *rootL = root->left;
            free(root);
            return rootL;
        }
        else
        {
            // find the minimum value of bst from right subtree
            TreeNode *mn = minValueNode(root->right);

            // copy it at the deleted value
            root->data = mn->data;

            // delete it from the right subtree
            root->right = deleteNode(root->right, mn->data);
        }
    }
    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    // Right Right Case
    else if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    // Left Right Case
    else if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    else if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inOrder(TreeNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int32_t main()
{
    tool();
    TreeNode *root = nullptr;

    root = insertNode(root, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 0);
    root = insertNode(root, 6);
    root = insertNode(root, 11);
    root = insertNode(root, -1);
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    preOrder(root);
    cout << "\n";
    root = deleteNode(root, 10);
    preOrder(root);
    return 0;
}