#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

int getMinInSubTree(Node* root)
{
  if(root == NULL)
    return INT_MAX;
  if(root->left == NULL and root->right == NULL)
    return 0;
  return 1 + min(getMinInSubTree(root->left), getMinInSubTree(root->right));
}

int closestLeafNode(Node* root, Node* node, int lvl, vector<Node*>& arr)
{
  if(root == NULL)
    return INT_MAX;
  
  int minDist = INT_MAX;

  if(root == node) 
  {
    minDist = min(minDist, getMinInSubTree(root));
    for(int i = lvl-1; i >= 0; i--)
      minDist = min(minDist, lvl-i+getMinInSubTree(arr[i]));
  }
  arr[lvl] = root;
  minDist = min(minDist, closestLeafNode(root->left, node, lvl+1, arr));
  if(minDist != INT_MAX)
    return minDist;
  return minDist = min(minDist, closestLeafNode(root->right, node, lvl+1, arr));
}

int height(Node* root)
{
  if(root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

int32_t main()
{
  Node *root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(13);
  root->right->left = new Node(14);
  root->right->right = new Node(15);
  root->right->left->left = new Node(21);
  root->right->left->right = new Node(22);
  root->right->right->left = new Node(23);
  root->right->right->right = new Node(24);
  root->right->left->left->left = new Node(1);
  root->right->left->left->right = new Node(2);
  root->right->left->right->left = new Node(3);
  root->right->left->right->right = new Node(4);
  root->right->right->left->left = new Node(5);
  root->right->right->left->right = new Node(6);
  root->right->right->right->left = new Node(7);
  root->right->right->right->right = new Node(8);
  int hgt = height(root);
  vector<Node*> arr(hgt);
  cout << closestLeafNode(root, root->right, 0, arr);
  return 0;
}