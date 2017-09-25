//Complete AVL tree
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int> ans;
int node_count = 0;
int n;
struct node {
	int data;
	int height;
	node*left;
	node *right;
};
int getHeight(node*root) {
	if (root == NULL) return 0;
	else  return root->height;
}
int getBalanceFactor(node*root) {
	return getHeight(root->left) - getHeight(root->right);
}
void updateHeight(node *root) {
	root->height =  max(getHeight(root->left), getHeight(root->right)) + 1;
}
void L(node *&root) {
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node *&root) {
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node *&root,int x) {
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
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->left) == 1) {
				R(root);
			}
			else if (getBalanceFactor(root->left) == -1) {
				L(root->left);
				R(root);
			}
		}
	}
	else {
		insert(root->right, x);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->right) == 1) {
				R(root->right);
				L(root);
			}
			else if (getBalanceFactor(root->right) == -1) {
				L(root);
			}
		}
	}
}
void bfs(node *root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node *front = q.front();
		q.pop();
		ans.push_back(front->data);
		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}
bool isCBT(node *root) {
	queue<node*> q;
	q.push(root);
	while (q.front() != NULL) {
		node *front = q.front();
		q.pop();
		node_count++;
		q.push(front->left);
		q.push(front->right);
	}
	if (node_count == n) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int temp;
	cin >> n;
	node *root = NULL;
	for (int i = 0; i < n;i++) {
		cin >> temp;
		insert(root, temp);
	}
	bfs(root);
	for (int i = 0; i < n;i++) {
		cout << ans[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
	cout << endl;
	bool flag = isCBT(root);
	if (flag) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}