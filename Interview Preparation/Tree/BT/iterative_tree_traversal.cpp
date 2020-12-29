#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> postOrder(TreeNode *);
vector<int> inOrder(TreeNode *);
vector<int> preOrder(TreeNode *);

int32_t main()
{
    tool();
    TreeNode* root = new TreeNode(20); 
    root->left = new TreeNode(10);  
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5);    
    root->left->right->right = new TreeNode(3);
    root->left->right->right->left=new TreeNode(6);
    root->left->right->right->right=new TreeNode(8);
    root->left->right->right->right->left=new TreeNode(11);

    vector<int> post = postOrder(root);
    for (int val : post)
        cout << val << " ";
    cout << "\n";
    vector<int> in = inOrder(root);
    for (int val : in)
        cout << val << " ";
    cout << "\n";
    vector<int> pre = preOrder(root);
    for (int val : pre)
        cout << val << " ";
    cout << "\n";
}

// left - right - push
vector<int> postOrder(TreeNode *root)
{
    stack<pair<TreeNode *, int>> s;
    vector<int> v;
    s.push({root, 0});
    while (!s.empty())
    {
        pair<TreeNode *, int>& cur = s.top();
        if (cur.first == nullptr)
        {
            s.pop();
            continue;
        }
        // left push
        else if (cur.second == 0)
            s.push({cur.first->left, 0});
        // right push
        else if (cur.second == 1)
            s.push({cur.first->right, 0});
        // print
        else if (cur.second == 2)
            v.push_back(cur.first->data);
        else
            s.pop();
        cur.second++;
    }
    return v;
}

// left - root - right
vector<int> inOrder(TreeNode *root)
{
    stack<pair<TreeNode *, int>> s;
    vector<int> v;
    s.push({root, 0});
    while (!s.empty())
    {
        pair<TreeNode *, int>& cur = s.top();
        if (cur.first == nullptr)
        {
            s.pop();
            continue;
        }
        // left push
        else if (cur.second == 0)
            s.push({cur.first->left, 0});
        // print
        else if (cur.second == 1)
            v.push_back(cur.first->data);
        // push right
        else if (cur.second == 2)
            s.push({cur.first->right, 0});
        else
            s.pop();
        cur.second++;
    }
    return v;
}

// root - left - right
vector<int> preOrder(TreeNode *root)
{
    stack<pair<TreeNode *, int>> s;
    vector<int> v;
    s.push({root, 0});
    while (!s.empty())
    {
        pair<TreeNode *, int>& cur = s.top();
        if (cur.first == nullptr)
        {
            s.pop();
            continue;
        }
        // print
        else if (cur.second == 0)
            v.push_back(cur.first->data);
        // left push
        else if (cur.second == 1)
            s.push({cur.first->left, 0});
        // push right
        else if (cur.second == 2)
            s.push({cur.first->right, 0});
        else
            s.pop();
        cur.second++;
    }
    return v;
}

