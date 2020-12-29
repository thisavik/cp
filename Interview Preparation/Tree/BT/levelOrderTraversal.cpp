#include <iostream>
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

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = left;
    }
};

// 2-queue method for level order traversal
void m_1(TreeNode* root) {
    if(root == nullptr) return;
    queue<TreeNode*> q1, q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty()) {
        while(!q1.empty()) {
            TreeNode* cur = q1.front();
            q1.pop();
            if(cur->left) q2.push(cur->left);
            if(cur->right) q2.push(cur->right);
            cout << cur->data << " ";
        }
        cout << "\n";
        while(!q2.empty()) {
            TreeNode* cur = q2.front();
            q2.pop();
            if(cur->left) q1.push(cur->left);
            if(cur->right) q1.push(cur->right);
            cout << cur->data << " ";
        }
        cout << "\n";
    }
}

// 1-queue & 1-delimiter methos for level order traversal
void m_2(TreeNode* root) {
    if(root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    TreeNode* cur;
    while(q.size() > 1) {
        cur = q.front();
        q.pop();
        if(cur == nullptr) {
            cout << "\n";
            q.push(nullptr);
        } else {
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            cout << cur->data << " ";
        }
    }
    cout << "\n";
}
int32_t main() {
    tool();
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    m_1(root);
    m_2(root);
    cout << "kjhjk";
    return 0;
}
 