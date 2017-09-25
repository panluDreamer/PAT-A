#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 35;
struct node {
	int data;
	node *left;
	node *right;
};
vector<int>inOrder1;
vector<int>inOrder2;
vector<int>postOrder1;
vector<int>postOrder2;
vector<int>levelOrder;
vector<int> tempOrder;
void insert(node *&root, int x) {
	if (root == NULL) {
		root = new node();
		root->data = x;
		root->left = root->right = NULL;
		return;
	}
	if (x < root->data) {
		insert(root->left, x);
	}
	else {
		insert(root->right, x);
	}
}
void in_order(node *root) {
	if (root == NULL) {
		return;
	}
	in_order(root->left);
	tempOrder.push_back(root->data);
	in_order(root->right);
}
void post_order(node *root) {
	if (root == NULL) {
		return;
	}
	post_order(root->left);
	post_order(root->right);
	tempOrder.push_back(root->data);
}
vector<int> fuzhi(vector<int> a) {
	vector<int> b;
	for (int i = 0; i < a.size();i++) {
		b.push_back(a[i]);
	}
	return b;
}
bool compare(vector<int> a,vector<int> b) {
	bool flag = true;
	for (int i = 0; i < a.size();i++) {
		if (a[i] != b[i]) {
			flag = false;
			break;
		}
	}
	return flag;
}
void level(node *root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node*front = q.front();
		q.pop();
		levelOrder.push_back(front->data);
		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}
int main() {
	int n;
	cin >> n;
	int num;
	node*root1 = NULL;
	node*root2 = NULL;
	for (int i = 0; i < n;i++) {
		cin >> num;
		insert(root1, num);
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		insert(root2, num);
	}
	tempOrder.clear();
	in_order(root1);
	inOrder1 = fuzhi(tempOrder);
	tempOrder.clear();
	in_order(root2);
	inOrder2 = fuzhi(tempOrder);
	tempOrder.clear();
	post_order(root1);
	postOrder1 = fuzhi(tempOrder);
	tempOrder.clear();
	post_order(root2);
	postOrder2 = fuzhi(tempOrder);
	if (compare(inOrder1,inOrder2)&&compare(postOrder1,postOrder2)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	for (int i = 0; i < n;i++) {
		cout << postOrder1[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
	cout << endl;
	level(root1);
	for (int i = 0; i < n; i++) {
		cout << levelOrder[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
}
