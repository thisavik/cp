#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// An BST Node 
class TreeNode {
public:
    int data, height;
    TreeNode *left, *right;
    TreeNode(int key) {
        data = key;
        left = right = nullptr;
    }
};

TreeNode* insertNode(TreeNode* root, int data) {
    if(!root)
        return new TreeNode(data);
    if(data < root->data)
        root->left = insertNode(root->left, data);
    else if(data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

TreeNode* minValueNode(TreeNode* root) {
    TreeNode* cur = root;
    while(root && root->left)
        root = root->left;
    return root;
}

TreeNode* maxValueNode(TreeNode* root) {
    TreeNode* cur = root;
    while(root && root->right)
        root = root->right;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == nullptr) {
            TreeNode* rootR = root->right;
            free(root);
            return rootR;
        }
        if(root->right == nullptr) {
            TreeNode* rootL = root->left;
            free(root);
            return rootL;
        }

        // find the minimum value of bst from right subtree
        TreeNode* mn = minValueNode(root->right);

        // copy it at the deleted value
        root->data = mn->data;

        // delete it from the right subtree 
        root->right = deleteNode(root->right, mn->data);
    }
    return root;
}

void inOrder(TreeNode* root) {
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(TreeNode* root) {
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(TreeNode* root) {
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int32_t main() {
    tool();
    TreeNode* root = nullptr;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    inOrder(root);
    cout << "\n";
    inOrderIter(root);
    preOrderRec(root);
    cout << "\n";
    preOrderIterM_1(root);
    cout << "\n";
    preOrderIterM_2(root);
    return 0;
}