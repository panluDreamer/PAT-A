#include<iostream>
#include<vector>
using namespace std;
vector<int> level;

vector<int>in;
vector<int> pre;
vector<int> post;
int n;
struct node {
	int data;
	node *left;
	node *right;
};
//ÖÐÐò¡¢²ãÐò½¨Ê÷
node *create(vector<int> layer, int inL,int inR) {
	if (layer.size() == 0) {
		return NULL;
	}
	node *root = new node();
	root->data = layer[0];
	int k;
	for (k = inL; k <= inR;k++) {
		if (in[k] == root->data) {
			break;
		}
	}
	//cout << "k=" << k << endl;
	vector<int> left_level;
	vector<int> right_level;
	for (int i = 1; i < layer.size();i++) {
		bool isLeft = false;
		for (int j = inL; j < k;j++) {
			if (in[j] == layer[i]) {
				isLeft = true;
				break;
			}
		}
		if (isLeft == true) {
			left_level.push_back(layer[i]);
		}
		else {
			right_level.push_back(layer[i]);
		}
	}
	//cout << "left size = " << left_level.size() << endl;
	//cout << "right size = " << right_level.size() << endl;
	root->left = create(left_level, inL, k - 1);
	root->right = create(right_level, k + 1, inR);
	return root;
}
void pre_order(node*root) {
	if (root == NULL) {
		return;
	}
	pre.push_back(root->data);
	pre_order(root->left);
	pre_order(root->right);
}
void post_order(node*root) {
	if (root == NULL) {
		return;
	}
	post_order(root->left);
	post_order(root->right);
	post.push_back(root->data);
}
int main() {
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
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << post[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
}