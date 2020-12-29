#include <iostream>
#include <vector>
using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct node { 
  int data; 
  node *left; 
  node *right; 
  node(int key) {
      data = key;
      left = nullptr;
      right = nullptr;
  }
};

void findPaths(node* root, vector<int>* curr, vector<vector<int>>& paths) {

    if(root == nullptr) return;
    curr->push_back(root->data);
    if(root->left == nullptr && root->right == nullptr) {
        paths.push_back(*curr);
        return;
    }

    findPaths(root->left, new vector<int>(*curr), paths);
    findPaths(root->right, new vector<int>(*curr), paths);
}

int32_t main() 
{
    tool();
    node *root = new node(1);  
    
    
    root->left = new node(2); 
    root->right = new node(3);   
    root->left->left = new node(4); 
    root->left->right = new node(5);  
    root->right->left = new node(6);
    root->right->right = new node(8);
    root->right->left->right = new node(7);
    root->left->right->left = new node(9); 

    vector<vector<int>> paths;
    findPaths(root, new vector<int>(), paths);

    for(auto& v: paths) {
        for(auto& val: v)
            cout << val << " ";
        cout << "\n";
    }
    return 0; 
} 


/*
#include <iostream>
using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct node{
	int value;
	node *left;
	node *right;
    node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class btree{
public:
	btree();
	~btree();

	void insert(int key);
	node *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	void inorder_print(node *leaf);
	void postorder_print(node *leaf);
	void preorder_print(node *leaf);

	node *root;
};

int main(){
    tool();
	//btree tree;
	btree *tree = new btree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	delete tree;

}



btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node(key);
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node(key);
        }
	}

}

void btree::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node(key);
	}
}

node *btree::search(int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

node *btree::search(int key){
	return search(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}

void btree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

*/