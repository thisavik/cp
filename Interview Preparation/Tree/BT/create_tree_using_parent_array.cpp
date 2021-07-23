#include <iostream>
#include <vector>

using namespace std;

void tool()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inOrder(TreeNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void createTree(vector<TreeNode *> &created, vector<int> &par, int s, TreeNode **root)
{
    if (created[s] != NULL)
        return;

    created[s] = new TreeNode(s);

    if (par[s] == -1) {
        *root = created[s];
        return;
    }
    else if (created[par[s]] == nullptr)
        createTree(created, par, par[s], root);
    if(!created[par[s]]->left)
        created[par[s]]->left = created[s];
    else
        created[par[s]]->right = created[s];
}

TreeNode *createTree(vector<int> &par)
{
    int n = par.size();
    vector<TreeNode *> created(n, NULL);

    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
        createTree(created, par, i, &root);
    return root;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> par(n);
    for (int &val : par)
        cin >> val;
    TreeNode *root = createTree(par);
    inOrder(root);
    cout << "\n";
}

int32_t main()
{
    tool();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
// iterative approach 
TreeNode *createTree(vector<int> &par)
{
    int n = par.size();
    vector<TreeNode *> created(n);
    for (int i = 0; i < n; i++)
        created[i] = new TreeNode(i);
    TreeNode *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (par[i] == -1)
            root = created[i];
        else if (!created[par[i]]->left)
            created[par[i]]->left = created[i];
        else
            created[par[i]]->right = created[i];
    }
    return root;
}
*/