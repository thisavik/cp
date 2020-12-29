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
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// O(n^2) Approach
Node* buildBst(Node *root, int val) {
    if(root == nullptr) return new Node(val);

    if(root->data > val)
        root->left = buildBst(root->left, val);
    else
        root->right = buildBst(root->right, val);
    return root;
}

// O(n^2) Approach
Node* createTree(int *pre, int size) {
    Node *root = nullptr;

    for(int i = 0; i < size; i++)
        root = buildBst(root, pre[i]);

    return root;
}

// O(n) Approach
Node* createTree_2(int *pre, int size) {
    if(size == 0)
        return nullptr;
    stack<Node*> stk;
    Node *root = new Node(pre[0]);
    stk.push(root);
    for(int i = 1; i < size; i++) {
        Node* node = new Node(pre[i]);
        Node *temp;
        while(!stk.empty() && stk.top()->data < pre[i]) {
            temp = stk.top();
            stk.pop();
        }
        if(temp == nullptr) {
            stk.top()->left = node;
        } else {
            temp->right = node;
        }
        stk.push(node);
    }
    return root;
}
void preorderT(Node *root) {
    if(!root) return;
    cout << root->data << " ";
    preorderT(root->left);
    preorderT(root->right);
}

void inorderT(Node *root) {
    if(!root) return;
    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}

void postorderT(Node *root) {
    if(!root) return;
    postorderT(root->left);
    postorderT(root->right);
    cout << root->data << " ";
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    int preorder[n];
    for(int& val : preorder)
        cin >> val;
    Node* root = createTree_2(preorder, n);
    if(root == nullptr) cout << "Not Possible";
    else {
        cout << "Possible\n";
        inorderT(root);
        cout << "\n";
        preorderT(root);
        cout << "\n";
        postorderT(root);
    }
    return 0;
}