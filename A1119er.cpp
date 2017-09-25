#include<iostream>
#include<vector>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
};
vector<int> post;
vector<int> pre;
vector<int> in;
bool isUnique = true;
node *create(int preL, int preR, int postL, int postR) {
	if (preL > preR) {
		return NULL;
	}
	node *root = new node();
	root->data = pre[preL];
	//root->left = root->right = NULL;
	if (preL == preR) return root;
	int k;
	int left_num = 0;
	for (k = postL; k <= postR - 1; k++) {
		left_num++;
		if (post[k] == pre[preL + 1]) {
			//k = i;
			break;
		}
	}
	//cout << "k=" << k << endl;
	if (k == postR - 1) {
		isUnique = false;
		//root->right = create(preL + 1, preR, postL, postR - 1);
	}
	//else {
	root->left = create(preL + 1, preL + left_num, postL, k);
	root->right = create(preL + left_num + 1, preR, k + 1, postR - 1);
	//}
	return root;
}
void inorder(node *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	in.push_back(root->data);
	inorder(root->right);
}
int main() {
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		pre.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		post.push_back(temp);
	}
	node *root = NULL;
	root = create(0, n - 1, 0, n - 1);
	if (isUnique) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	inorder(root);
	for (int i = 0; i < n; i++) {
		cout << in[i];
		if (i != n - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
}