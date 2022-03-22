#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node* left, *right;
};
struct Node* newNode(int data)
{
	struct Node* node = new(struct Node);
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
int max(int a, int b)
{ return (a >= b)? a: b; }
int maxPathSumUtil(struct Node *root, int &res)
{
	if (root==NULL) return 0;
	if (!root->left && !root->right) return root->data;
	int ls = maxPathSumUtil(root->left, res);
	int rs = maxPathSumUtil(root->right, res);
	if (root->left && root->right)
	{
		res = max(res, ls + rs + root->data);
		return max(ls, rs) + root->data;
	}
	return (!root->left)? rs + root->data : ls + root->data;
}
int maxPathSum(struct Node *root)
{
	int res = INT_MIN;
	int val = maxPathSumUtil(root, res);
	if(res == INT_MIN)
	{
	return val;
	}
	return res;
}
class Solution {
public:
    int solve(Node* root,int &res){
       if(!root)
           return 0;
       if(root->left==NULL && root->right==NULL){
           return root->data;
       }
       int l=solve(root->left,res);
       int r=solve(root->right,res);
       if(root->left && root->right){
           int temp=max(l,r)+root->data;
           int ans=(l+r+root->data);
           res=max(res,ans);
           return temp;
       }
       if(root->left==NULL){
           int temp=r+root->data;
           return temp;
       }
       if(root->right==NULL){
           int temp=l+root->data;
           return temp;
       }
   }
   int maxPathSum(Node* root)
   {
       int res=INT_MIN;
       int ans=solve(root,res);
       if(res!=INT_MIN){
           return res;
       }
       else{
           return ans;
       }
   }
};
int main()
{
	struct Node *root = newNode(7);
	root->left = newNode(5);
	cout << "Max pathSum of the given binary tree is "
		<< maxPathSum(root);
    Solution s;
    cout << "\n" << s.maxPathSum(root);
	return 0;
}
