#include <iostream>
#include <stack>
#include <queue>

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

void inOrder(Node* root) {
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int maxLevel = 0;
void printRightView(Node* root, int level = 1) {
    if(!root)
        return;
    if(maxLevel < level) {
        cout << root->data << " ";
        maxLevel = level;
    }
    printRightView(root->right, level+1);
    printRightView(root->left, level+1);   
}

void printRightViewIt(Node* root) {
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    Node* cur;
    while(!q.empty()) {
        int cnt = q.size();
        for(int i = 0; i < cnt; i++) {
            cur = q.front();
            q.pop();
            if(i == cnt-1) 
                cout << cur->data << " ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
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
    printRightView(root);
    cout << "\n";
    printRightViewIt(root);
    return 0;
}