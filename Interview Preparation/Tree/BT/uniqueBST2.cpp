// https://leetcode.com/problems/unique-binary-search-trees-ii/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct TreeNode {
    int data;
    TreeNode* left, *right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr; 
    }
};

map<pair<int, int>, vector<TreeNode*>> lookUp;

vector<TreeNode*> helper(int s, int e) {
    vector<TreeNode*> res;
    if(s > e) {
        res.push_back(nullptr);
        return res;
    }
    if(lookUp.find({s, e}) != lookUp.end())
        return lookUp[{s, e}];
    for(int i = s; i <= e; i++) {
        vector<TreeNode*> left = helper(s, i-1);
        lookUp[{s, i-1}] = left;
        vector<TreeNode*> right = helper(i+1, e);
        lookUp[{i+1, e}] = right;
        for(auto l : left) {
            for(auto r : right) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if(n == 0) return vector<TreeNode*>();
    return helper(1, n);
}

void inOrder(TreeNode* root) {
    if(root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void solve() {
    int n;
    cin >> n;
    vector<TreeNode*> ans = generateTrees(n);
    for(auto t : ans) {
        inOrder(t);
        cout << "\n";
    }
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}