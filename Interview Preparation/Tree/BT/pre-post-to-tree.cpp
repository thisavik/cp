#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
  int data;
  TreeNode *left, *right;
  TreeNode(int key): data(key), left(NULL), right(NULL) {}
};

TreeNode* helper(vector<int>& pre, int &n, int& preIdx, int i, int j, unordered_map<int, int>& mp)
{
  if(preIdx >= n or i > j)
    return NULL;
  TreeNode* root = new TreeNode(pre[preIdx]);
  preIdx++;
  int idx = mp[pre[preIdx]];
  root->left = helper(pre, n, preIdx, i, idx, mp);
  root->right = helper(pre, n, preIdx, idx+1, j, mp);
  return root;
}

void preorder(TreeNode* root) 
{
  if(root == NULL)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(TreeNode* root) 
{
  if(root == NULL)
    return;
  preorder(root->left);
  cout << root->data << " ";
  preorder(root->right);
}
void postorder(TreeNode* root) 
{
  if(root == NULL)
    return;
  preorder(root->left);
  preorder(root->right);
  cout << root->data << " ";
}

int main()
{
  vector<int> pre = { 1, 2, 4, 5, 3, 6, 7 };
  vector<int> post = { 4, 5, 2, 6, 7, 3, 1 };
  unordered_map<int, int> mp;
  int n = pre.size();
  for(int i = 0; i < n; i++)
    mp[post[i]] = i;
  int preIdx = 0;
  TreeNode* root = helper(pre, n, preIdx, 0, n-1, mp);
  preorder(root);
  cout << "\n";
  inorder(root);
  cout << "\n";
  postorder(root);
  cout << "\n";
  return 0;
}