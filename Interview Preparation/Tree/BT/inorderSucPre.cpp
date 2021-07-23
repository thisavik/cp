#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

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

Node *insert(Node *root, int data)
{
  if(root == nullptr)
    return new Node(data);
  if(root->data < data)
    root->right = insert(root->right, data);
  else if(root->data > data)
    root->left = insert(root->left, data);
  return root;
}

void inorderSucPre(Node *root, Node *&pre, Node *&suc, int key)
{
  if(root == nullptr)
    return;
  if(root->data == key)
  {
    Node *temp;
     // predecessor
    if(root->left)
    {
      temp = root->left;
      while(temp && temp->right)
        temp = temp->right;
      pre = temp;
    }
     // sucessor
    if(root->right)
    {
      temp = root->right;
      while(temp && temp->left)
        temp = temp->left;
      suc = temp;
    }
    return;
  }
  if(root->data < key)
  {
    pre = root;
    inorderSucPre(root->right, pre, suc, key);
  } else 
  {
    suc = root;
    inorderSucPre(root->left, pre, suc, key);
  }
}

void inOrder(Node *root)
{
  if(root == nullptr)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

int main()
{
    int key = 65;    //Key to be searched in BST
 
   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    inOrder(root);
    cout << "\n";
 
    Node* pre = nullptr, *suc = nullptr;
 
    inorderSucPre(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
    return 0;
}