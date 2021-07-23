#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int key)
  {
    data = key;
    left = nullptr;
    right = nullptr;
  }
};


void printLeft(Node *root) 
{
  if(root == nullptr)
    return;
  if(root->left) {
    cout << root -> data << " ";
    printLeft(root->left);
  } else if(root->right) {
    cout << root -> data << " ";
    printLeft(root->right);
  }
}

void printRight(Node *root) 
{
  if(root == nullptr)
    return;
  if(root->right) {
    printRight(root->right);
    cout << root -> data << " ";
  } else if(root->left) {
    printRight(root->left);
    cout << root -> data << " ";
  }
}

void printLeaf(Node *root)
{
  if(root == nullptr)
    return;
  if(!root->left && !root->right)
  {
    cout << root->data << " ";
  }
  printLeaf(root->left);
  printLeaf(root->right);
}

void boundaryView(Node *root) 
{
  if(root == nullptr)
    return;
  cout << root->data << " ";
  
  // print left boundary of tree in top down manner
  printLeft(root->left);

  // print leaves in left to right manner
  printLeaf(root->left);
  printLeaf(root->right);

  // print right boundary of tree in bottom up manner 
  printRight(root);
}

int32_t main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(8);
  root->right->left->right = new Node(7);
  root->left->right->left = new Node(9);
  root->left->right->left->left = new Node(10);
  boundaryView(root);
  return 0;
}