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

Node *newNode(int data)
{
  return new Node(data);
}

void findInSubTree(Node *root, int level, int &minDist)
{
  if (root == NULL)
    return;
  if (root->left == NULL and root->right == NULL)
  {
    minDist = min(minDist, level);
    return;
  }
  findInSubTree(root->left, level + 1, minDist);
  findInSubTree(root->right, level + 1, minDist);
}

int findThroughParent(Node *root, Node *x, int &minDist)
{
  if (root == NULL)
    return -1;
  if (root == x)
    return 0;
  int l = findThroughParent(root->left, x, minDist);
  if (l != -1)
  {
    findInSubTree(root->right, l + 2, minDist);
    return l + 1;
  }

  int r = findThroughParent(root->right, x, minDist);
  if (r != -1)
  {
    findInSubTree(root->left, r + 2, minDist);
    return r + 1;
  }
  return -1;
}

int closestLeafNode(Node *root, Node *x)
{
  int minDist = INT_MAX;
  findInSubTree(x, 0, minDist);
  findThroughParent(root, x, minDist);
  return minDist;
}

int32_t main()
{
  Node *root = newNode(1);
  root->left = newNode(12);
  root->right = newNode(13);
  root->right->left = newNode(14);
  root->right->right = newNode(15);
  root->right->left->left = newNode(21);
  root->right->left->right = newNode(22);
  root->right->right->left = newNode(23);
  root->right->right->right = newNode(24);
  root->right->left->left->left = newNode(1);
  root->right->left->left->right = newNode(2);
  root->right->left->right->left = newNode(3);
  root->right->left->right->right = newNode(4);
  root->right->right->left->left = newNode(5);
  root->right->right->left->right = newNode(6);
  root->right->right->right->left = newNode(7);
  root->right->right->right->right = newNode(8);

  cout << closestLeafNode(root, root->right->right);
  return 0;
}