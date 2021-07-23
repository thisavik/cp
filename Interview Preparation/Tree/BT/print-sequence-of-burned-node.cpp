#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left, *right;
  TreeNode(int data): data(data), left(nullptr), right(nullptr) {}
};

auto burnTreeRec(TreeNode* root, int target, queue<TreeNode*> &q, vector<vector<int>> &ans)
{
  if(root == nullptr)
    return 0;
  vector<int> arr;
  if(root->data == target)
  {
    arr.push_back(root->data);
    ans.push_back(arr);
    if(root->left) q.push(root->left);
    if(root->right) q.push(root->right);
    return 1;
  }
  int a = burnTreeRec(root->left, target, q, ans);
  if(a == 1)
  {
    int qSize = q.size();
    while(qSize--)
    {
      auto node = q.front();
      arr.push_back(node->data);
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
      q.pop();
    }
    if(root->right)
      q.push(root->right);
    arr.push_back(root->data);
    ans.push_back(arr);
    return 1;
  }
  int b = burnTreeRec(root->right, target, q, ans);
  if(b == 1)
  {
    int qSize = q.size();
    while(qSize--)
    {
      auto node = q.front();
      q.pop();
      arr.push_back(node->data);
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    }
    if(root->left)
      q.push(root->left);
    arr.push_back(root->data);
    ans.push_back(arr);
    return 1;
  }
  return 0;
}

auto burnTree(TreeNode* root, int target)
{
  queue<TreeNode*> q;
  vector<vector<int>> ans; 
  burnTreeRec(root, target, q, ans);
  while(!q.empty())
  {
    int qSize = q.size();
    vector<int> arr;
    while(qSize--)
    {
      auto node = q.front();
      q.pop();
      arr.push_back(node->data);
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    }
    ans.push_back(arr);
  }
  return ans;
}

int32_t main()
{
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(13);
  root->right = new TreeNode(10);
  root->right->left = new TreeNode(14);
  root->right->right = new TreeNode(15);
  root->right->left->left = new TreeNode(21);
  root->right->left->right = new TreeNode(24);
  root->right->right->left = new TreeNode(22);
  root->right->right->right = new TreeNode(23);
  // vector<int> ans = burnTree(root, 14);
  // for(auto &val: ans)
  // {
  //  val == -1 ? cout << "\n" : cout << val << " ";
  // }
  vector<vector<int>> ans = burnTree(root, 14);
  for(auto &val: ans)
  {
    for(auto &v: val)
    {
      cout << v << " ";
    }
    cout << "\n";
  }
  return 0;
}