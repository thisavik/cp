#include <iostream>
#include <unordered_map>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
}

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// // O(N^2) Approach
// Node* createTree(int *in, int *pre, int is, int ie, int ps, int pe) {
//     if(is > ie || ps > pe) 
//         return nullptr;

//     Node* node = new Node(pre[ps]);

//     int pos;
//     for(int i = is; i <= ie; i++) {
//         if(in[i] == pre[ps]) {
//             pos = i;
//             break;
//         }
//     }

//     node->left = createTree(in, pre, is, pos-1, ps+1, ps+pos-is);
//     node->right = createTree(in, pre, pos+1, ie, ps+pos-is+1, pe);
//     return node;
// }

// // O(N^2) Approach
// Node* createTree(int *in, int *pre, int size) {
//     return createTree(in, pre, 0, size-1, 0, size-1);
// }

// check if creating tree possible or not
bool check(int *in, int *pre, int is, int ie, int ps, int pe, unordered_map<int, int>& mp) {
    if(is > ie || ps > pe) 
        return true;

    int pos = mp[pre[ps]];
    
    if(pos < is || pos > ie)
        return false;

    bool left = check(in, pre, is, pos-1, ps+1, ps+pos-is, mp);
    bool right = check(in, pre, pos+1, ie, ps+pos-is+1, pe, mp);
    return left && right;
}

// O(N) Approach-1
Node* createTree(int *in, int *pre, int is, int ie, int ps, int pe, unordered_map<int, int>& mp) {
    if(is > ie || ps > pe) 
        return nullptr;

    Node* node = new Node(pre[ps]);

    int pos = mp[pre[ps]];

    node->left = createTree(in, pre, is, pos-1, ps+1, ps+pos-is, mp);
    node->right = createTree(in, pre, pos+1, ie, ps+pos-is+1, pe, mp);
    return node;
}

// O(N) Approach-1
Node* createTree(int *in, int *pre, int size) {
    unordered_map<int, int> mp;
    for(int i = 0; i < size; i++)
        mp[in[i]] = i;
    if(check(in, pre, 0, size-1, 0, size-1, mp))
        return createTree(in, pre, 0, size-1, 0, size-1, mp);
    else
        return nullptr;
}

// check if creating tree possible or not
bool check_2(int *pre, int& p, int l, int r, unordered_map<int, int>& mp) {
    if(l > r) 
        return true;

    int pos = mp[pre[p]];
    
    if(pos < l || pos > r)
        return false;
    p++;
    bool left = check_2(pre, p, l, pos-1, mp);
    bool right = check_2(pre, p, pos+1, r, mp);
    return left && right;
}

// O(N) Approach-2
Node* createTree_2(int *pre, int& p, int l, int r, unordered_map<int, int>& mp) {
    if(l > r) 
        return nullptr;

    Node* node = new Node(pre[p]);
    int pos = mp[pre[p]];
    p++;

    node->left = createTree_2(pre, p, l, pos-1, mp);
    node->right = createTree_2(pre, p, pos+1, r, mp);
    return node;
}

// O(N) Approach-2
Node* createTree_2(int *in, int *pre, int size) {
    unordered_map<int, int> mp;
    for(int i = 0; i < size; i++)
        mp[in[i]] = i;
    int p = 0;
    if(check_2(pre, p, 0, size-1, mp)) {
        p = 0;
        return createTree_2(pre, p, 0, size-1, mp);
    }
    else
        return nullptr;
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
    int inorder[n], preorder[n];
    for(int& val : inorder)
        cin >> val;
    for(int& val : preorder)
        cin >> val;
    Node* root = createTree_2(inorder, preorder, n);
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