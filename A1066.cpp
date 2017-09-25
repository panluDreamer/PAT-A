//Root of AVL tree
#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int data;
	int height;
	node*left;
	node*right;
};
int getHeight(node *root) {
	if (root == NULL) return 0;
	else return root->height;
}
int getBalancedFactor(node *root) {
	return getHeight(root->left) - getHeight(root->right);
}
void updateHeight(node *root) {
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
void L(node*&root) {
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node*&root) {
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node*&root, int x) {
	if (root == NULL) {
		root = new node();
		root->data = x;
		root->height = 1;
		root->left = root->right = NULL;
		return;
	}
	if (x < root->data) {
		insert(root->left, x);
		updateHeight(root);
		if (getBalancedFactor(root) == 2) {
			if (getBalancedFactor(root->left) == 1) {
				R(root);
			}
			else if (getBalancedFactor(root->left) == -1) {
				L(root->left);
				R(root);
			}
		}
	}
	else {
		insert(root->right, x);
		updateHeight(root);
		if (getBalancedFactor(root) == -2) {
			if (getBalancedFactor(root->right) == -1) {
				L(root);
			}
			else if (getBalancedFactor(root->right) == 1) {
				R(root->right);
				L(root);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	int temp;
	node *root = NULL;
	for (int i = 0; i < n;i++) {
		cin >> temp;
		insert(root, temp);
	}
	cout << root->data << endl;
}