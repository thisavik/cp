#include <iostream>
#include <vector>
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

void postOrder(Node* root) {
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// iterative 2-stack method, O(N) Space complexity, O(N) time complexity
void postOrderItM_1(Node* root) {
    if(!root)
        return;
    stack<Node*> s1, s2;

    s1.push(root);
    Node* cur;
    while(!s1.empty()) {
        cur = s1.top();
        s1.pop();
        s2.push(cur);
        if(cur->left)
            s1.push(cur->left);
        if(cur->right)
            s1.push(cur->right);
    }
    while(!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// iterative 1-stack method
void postOrderItM_2(Node* root) {
    if(!root)
        return;
    stack<Node*> s;
    Node* cur = root;
    while(cur != nullptr || !s.empty()) {
        if(cur != nullptr) {
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top()->right;
            if(cur == nullptr) {
                cur = s.top();
                s.pop();
            }
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

    postOrder(root);
    cout << "\n";
    postOrderItM_1(root);
    return 0;
}