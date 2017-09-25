//深刻理解递归建树
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 35;
int preOrder[maxn];
int postOrder[maxn];
int n;
vector<int> inOrder;
struct node {
	int data;
	node *left;
	node *right;
};
node *root = NULL;
bool flag = true;
node *create(int preL, int preR, int postL, int postR) {
	if (preL > preR) {
		return NULL;
	}
	node * root = new node();
	root->data = preOrder[preL];
	root->left = root->right = NULL;
	if (preL == preR) {
		return root;
	}
	int k;
	for (k = preL + 1; k <= preR; k++) {
		if (preOrder[k] == postOrder[postR - 1]) {
			break;
		}
	}
	if (k - preL > 1) {
		root->left = create(preL + 1, k - 1, postL, postL + k - preL - 2);
		root->right = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	else {
		flag = false;
		root->right = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	return root;
}
void in_order(node *root) {
	if (root == NULL) {
		return;
	}
	in_order(root->left);
	inOrder.push_back(root->data);
	in_order(root->right);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> preOrder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postOrder[i];
	}
	root = create(0, n - 1, 0, n - 1);
	if (flag == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	in_order(root);
	for (int i = 0; i < n; i++) {
		cout << inOrder[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
	cout << endl;
}
