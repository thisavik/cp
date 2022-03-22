#include <bits/stdc++.h>
using namespace std;

#include "../../../algo/debug.h"
struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorder(TreeNode *root)
{
  vector<int> res;
  TreeNode *cur = root;
  TreeNode *prev = NULL;
  while (cur != NULL)
  {
    if (cur->left == NULL)
    {
      res.push_back(cur->val);
      cur = cur->right;
    }
    else
    {
      prev = cur->left;
      while (prev->right != NULL && prev->right != cur)
        prev = prev->right;
      if (prev->right == NULL)
      {
        prev->right = cur;
        cur = cur->left;
      }
      else
      {
        prev->right = NULL;
        res.push_back(cur->val);
        cur = cur->right;
      }
    }
  }
  return res;
}

vector<int> preorder(TreeNode *root)
{
  vector<int> res;
  TreeNode *cur = root;
  TreeNode *prev = NULL;
  while (cur != NULL)
  {
    if (cur->left == NULL)
    {
      res.push_back(cur->val);
      cur = cur->right;
    }
    else
    {
      prev = cur->left;
      while (prev->right != NULL && prev->right != cur)
        prev = prev->right;
      if (prev->right == NULL)
      {
        prev->right = cur;
        res.push_back(cur->val);
        cur = cur->left;
      }
      else
      {
        prev->right = NULL;
        cur = cur->right;
      }
    }
  }
  return res;
}

vector<int> postorder(TreeNode *root)
{
  vector<int> res;
  TreeNode *cur = root;
  TreeNode *prev = NULL;
  while (cur != NULL)
  {
    if (cur->left == NULL)
    {
      res.push_back(cur->val);
      cur = cur->right;
    }
    else
    {
      prev = cur->left;
      while (prev->right != NULL && prev->right != cur)
        prev = prev->right;
      if (prev->right == NULL)
      {
        prev->right = cur;
        res.push_back(cur->val);
        cur = cur->left;
      }
      else
      {
        prev->right = NULL;
        cur = cur->right;
      }
    }
  }
  return res;
}

vector<int> morrisPostorderTraversal(TreeNode *root);

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->left->right->right = new TreeNode(7);
  root->left->right->right->left = new TreeNode(8);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(10);
  root->right->left->right = new TreeNode(11);
  auto resInorder = inorder(root);
  for (auto x : resInorder)
    cout << x << " \n"[x == resInorder.back()];
  auto resPreorder = preorder(root);
  for (auto x : resPreorder)
    cout << x << " \n"[x == resPreorder.back()];
  auto resPostorder = morrisPostorderTraversal(root);
  for (auto x : resPostorder)
    cout << x << " \n"[x == resPostorder.back()];
}

// This is Post Order :children before node( L ,R , N)
vector<int> morrisPostorderTraversal(TreeNode *root)
{
  vector<int> res;
  // Making our tree left subtree of a dummy TreeNode
  TreeNode *dummyRoot = new TreeNode(0);
  dummyRoot->left = root;

  // Think of P as the current node
  TreeNode *p = dummyRoot, *pred, *first, *middle, *last;
  while (p != NULL)
  {
    if (p->left == NULL)
    {
      p = p->right;
    }
    else
    {
      /* p has a left child => it also has a predeccessor
         make p as right child predeccessor of p
      */
      pred = p->left;
      while (pred->right != NULL && pred->right != p)
      {
        pred = pred->right;
      }
      if (pred->right == NULL)
      {
        // predeccessor found for first time
        // modify the tree
        pred->right = p;
        p = p->left;
      }
      else
      {
        // predeccessor found second time
        // reverse the right references in chain from pred to p
        first = p;
        middle = p->left;
        while (middle != p)
        {
          last = middle->right;
          middle->right = first;
          first = middle;
          middle = last;
        }
        // visit the nodes from pred to p
        // again reverse the right references from pred to p
        first = p;
        middle = pred;
        while (middle != p)
        {
          res.push_back(middle->val);
          // cout << " " << middle->val;
          last = middle->right;
          middle->right = first;
          first = middle;
          middle = last;
        }
        // remove the pred to node reference to restore the tree structure
        pred->right = NULL;
        trace(res);
        p = p->right;
      }
    }
  }
  return res;
}