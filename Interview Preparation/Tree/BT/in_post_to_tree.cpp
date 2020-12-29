#include <iostream>
#include <unordered_map>

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

// O(n) Approach
Node* createTree(int *in, int *post, int is, int ie, int ps, int pe, unordered_map<int, int>& mp) {
    if(is > ie || ps > pe) 
        return nullptr;

    Node* node = new Node(post[pe]);

    int pos = mp[post[pe]];

    node->left = createTree(in, post, is, pos-1, ps, pe+pos-ie-1, mp);
    node->right = createTree(in, post, pos+1, ie, pe+pos-ie, pe-1, mp);
    return node;
}

// O(N) Approach
Node* createTree(int *in, int *post, int size) {
    unordered_map<int, int> mp;
    for(int i = 0; i < size; i++)
        mp[in[i]] = i;
    return createTree(in, post, 0, size-1, 0, size-1, mp);
}

void postorderT(Node *root) {
    if(!root) return;
    postorderT(root->left);
    postorderT(root->right);
    cout << root->data << " ";
}

void inorderT(Node *root) {
    if(!root) return;
    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}

int32_t main() {
    tool();
    int n;
    cin >> n;
    int inorder[n], postorder[n];
    for(int& val : inorder)
        cin >> val;
    for(int& val : postorder)
        cin >> val;

    Node* root = createTree(inorder, postorder, n);
    inorderT(root);
    cout << "\n";
    postorderT(root);
    return 0;
}