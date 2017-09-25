#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
};
vector<int> level;
vector<int> in;
vector<int>pre;
vector<int> post;
int rightToLeft = 0;
int rightupToLeftdown = 0;
int upToDown = 0;
int leftnum = 0, rightnum = 0;
node *create(vector<int>lay, int inL, int inR) {
	if (lay.size() == 0) {
		return NULL;
	}
	node *root = new node();
	root->data = lay[0];
	int k = -1;
	for (k = inL; k <= inR; k++) {
		if (in[k] == lay[0]) {
			break;
		}
	}
	vector<int> left_level;
	vector<int> right_level;
	for (int i = 1; i < lay.size(); i++) {
		bool isLeft = false;
		for (int j = inL; j < k; j++) {
			if (in[j] == lay[i]) {
				isLeft = true;
			}
		}
		if (isLeft) {
			left_level.push_back(lay[i]);
		}
		else {
			right_level.push_back(lay[i]);
		}
	}
	root->left = create(left_level, inL, k - 1);
	root->right = create(right_level, k + 1, inR);
	return root;
}
void pre_order(node *root) {
	if (root == NULL) {
		return;
	}
	pre.push_back(root->data);
	pre_order(root->left);
	pre_order(root->right);
}
void post_order(node *root) {
	if (root == NULL) {
		return;
	}
	post_order(root->left);
	post_order(root->right);
	post.push_back(root->data);
}
void dfs1(node *root, int depth) {
	if (root == NULL) {
		return;
	}
	if (depth > rightToLeft) {
		rightToLeft = depth;
	}
	dfs1(root->left, depth + 1);
	dfs1(root->right, depth + 1);
}
void dfs2(node *root, int depth) {
	if (root == NULL) {
		return;
	}
	if (depth > rightupToLeftdown) {
		rightupToLeftdown = depth;
	}
	dfs2(root->left, depth);
	dfs2(root->right, depth + 1);
}
void dfs3(node *root, int depth) {
	if (root == NULL) {
		return;
	}
	if (depth > 0 && depth > rightnum) {
		rightnum = depth;
	}
	if (depth < 0 && depth < leftnum) {
		leftnum = depth;
	}
	dfs3(root->left, depth - 1);
	dfs3(root->right, depth + 1);
}
int main() {
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		level.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		in.push_back(temp);
	}
	node *root = NULL;
	root = create(level, 0, n - 1);
	pre_order(root);
	post_order(root);
	for (int i = 0; i < n; i++) {
		cout << pre[i];
		if (i != n - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << post[i];
		if (i != n - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
	if (n == 1) {
		cout << "1" << endl;
		cout << "1" << endl;
		cout << "1" << endl;
		return 0;
	}
	dfs1(root, 1);
	cout << rightToLeft << endl;
	dfs2(root, 1);
	cout << rightupToLeftdown << endl;
	dfs3(root, 1);
	//cout << leftnum << " " << rightnum << endl;
	upToDown = abs(leftnum) + rightnum + 1;
	cout << upToDown << endl;
}