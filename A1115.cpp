#include<iostream>
#include<queue>
using namespace std;
int maxlevel = 0;
int n1 = 0, n2 = 0;
struct node {
	int data;
	node *left;
	node *right;
	int level;
};
void insert(node*&root, int data) {
	if (root == NULL) {
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if (data > root->data) {
		insert(root->right, data);
	}
	else {
		insert(root->left, data);
	}
}
void bfs(node *root) {
	queue<node*> q;
	root->level = 1;
	q.push(root);
	while (!q.empty()) {
		node* front = q.front();
		q.pop();
		if (front->level > maxlevel) {
			maxlevel = front->level;
		}
		if (front->left != NULL) {
			front->left->level = front->level + 1;
			q.push(front->left);
		}
		if (front->right != NULL) {
			front->right->level = front->level + 1;
			q.push(front->right);
		}
	}
}
void bfs2(node *root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node*front = q.front();
		q.pop();
		if (front->level == maxlevel) {
			n1++;
		}
		else if (front->level == maxlevel - 1) {
			n2++;
		}
		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}
int main() {
	int n, data;
	node*root = NULL;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data;
		insert(root, data);
	}
	bfs(root);
	//	cout << "maxlevel = " << maxlevel << endl;
	bfs2(root);
	cout << n1 << " + " << n2 << " = " << n1 + n2;
	return 0;
}
