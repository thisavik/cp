#include <iostream>
using namespace std;
void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class Node {
	int data;
	Node* left;
	Node* right;
public:
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
	Node* constructBST(int arr[], int n) {
		if (n == 0)
			return NULL;
		Node* root = NULL;
		for (int i = 0; i < n; i++)
			root = levelOrder(root, arr[i]);
		return root;
	}
	Node* levelOrder(Node* root, int data) {
		if (root == NULL) {
			root = new Node(data);
			return root;
		}
		if (data <= root->data) {
			root->left = levelOrder(root->left, data);
		} else {
			root->right = levelOrder(root->right, data);
		}
		return root;
	}
	void inorderTraversal(Node* root) {
		if (root == NULL)
			return;
		inorderTraversal(root->left);

		cout << root->data << " ";

		inorderTraversal(root->right);
	}
};
int main() {
	tool();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	Node* root = root->constructBST(arr, n);
	root->inorderTraversal(root);
	return 0;
}