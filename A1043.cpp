#include<iostream>
#include<vector>
using namespace std;
vector<int> origin, pre, mirr_pre, post, mirr_post;
struct node {
	int data;
	node *left;
	node *right;
};
bool cmp1(int a, int b) {
	return a <= b;
}
bool cmp2(int a, int b) {
	return a >= b;
}
void insert(node *&root, int data) {
	if (root == NULL) {
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if (data < root->data) insert(root->left, data);
	else insert(root->right, data);
}
void preOrder(node *root) {
	if (root == NULL) {
		return;
	}
	pre.push_back(root->data);
	preOrder(root->left);
	preOrder(root->right);
}
void mirrPre(node *root) {
	if (root == NULL) {
		return;
	}
	mirr_pre.push_back(root->data);
	mirrPre(root->right);
	mirrPre(root->left);
}
void postOrder(node *root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	post.push_back(root->data);
}
void mirrPost(node *root) {
	if (root == NULL) {
		return;
	}
	mirrPost(root->right);
	mirrPost(root->left);
	mirr_post.push_back(root->data);
}
int main() {
	int n, temp;
	cin >> n;
	node *root = NULL;//一定记得要初始化,赋值NULL
	for (int i = 0; i < n; i++) {
		cin >> temp;
		origin.push_back(temp);
		insert(root, temp);
	}
	preOrder(root);
	mirrPre(root);
	postOrder(root);
	mirrPost(root);
	if (origin == pre) {
		cout << "YES" << endl;
		for (int i = 0; i < post.size() - 1; i++) {
			cout << post[i] << " ";
		}
		cout << post[post.size() - 1] << endl;
	}
	else if (origin == mirr_pre) {
		cout << "YES" << endl;
		for (int i = 0; i < mirr_post.size() - 1; i++) {
			cout << mirr_post[i] << " ";
		}
		cout << mirr_post[mirr_post.size() - 1] << endl;
	}
	else {
		cout << "NO" << endl;
	}
}