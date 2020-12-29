#include <iostream>
#include <stack>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct Node {
  int data; 
  Node *left; 
  Node *right; 
  Node(int key) {
      data = key;
      left = nullptr;
      right = nullptr;
  }
};

// O(N) time complexity
// O(H) space complexity
void preOrder(Node* root) {
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Iterative 1 stack method
// O(N) time complexity
// O(H) space complexity
void preOrderIt(Node* root) {
    if(!root)
        return;
    stack<Node*> s;
    Node* cur = root;
    while(cur != nullptr || !s.empty()) {
        while(cur != nullptr) {
            cout << cur->data << " ";
            if(cur->right) 
                s.push(cur->right);
            cur = cur->left;
        }
        if(!s.empty()) {
            cur = s.top();
            s.pop();
        }
    }
}

int32_t main() 
{
    tool();
    Node *root = new Node(1);  
    root->left = new Node(2); 
    root->right = new Node(3);   
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    root->right->left->right = new Node(7);
    root->left->right->left = new Node(9); 

    preOrder(root);
    cout << "\n";
    preOrderIt(root);
    return 0;
}