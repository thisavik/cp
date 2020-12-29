#include <iostream>
#include <stack>
using namespace std;


void inOrderTraversalUsingStack(Node* root) {
	stack<Node*> s;
	Node* curr = root;
	while (curr != NULL || !s.empty()) {
		while (curr != NULL) {
			s.push(curr);
			curr = curr ->left;
		}
		curr = s.top();
		s.pop();

		cout << curr->data << " ";

		curr = curr->right;
	}
}
void preOrderTraversalUsingStack(Node* root) {
	stack<Node*> s;
	Node* curr = root;

	while (curr != NULL || !s.empty()) {
		cout << curr->data << " ";

		if (curr->right != NULL)
			s.push(curr->right);

		if (curr->left != NULL)
			s.push(curr->left);

		curr = s.top();
		s.pop();
	}
}
void preOrderTraversalUsingStack(Node* root) {
	stack<Node*> s;
	Node* curr = root;
	while (curr != NULL || !s.empty()) {
		while (curr != NULL) {
			cout << curr->data << " ";
			if (curr->right != NULL)
				s.push(curr->right);
			curr = curr->left;
		}
		if (!s.empty()) {
			curr = s.top();
			s.pop();
		}
	}
}

void inOrderTraversal(Node* root) {
	if (root == NULL)
		return;
	inOrderTraversal(root->left);

	cout << root->data << " ";

	inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root) {
	if (root == NULL)
		return root;
	cout << root->data << " ";

	preOrderTraversal(root->left);

	preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root) {
	if (root == NULL)
		return;
	postOrderTraversal(root->left);

	postOrderTraversal(root->right);

	cout << root->data << " ";
}