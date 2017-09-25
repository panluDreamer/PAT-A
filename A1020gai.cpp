#include<iostream>
#include<queue>
using namespace std;
const int maxn = 35;
int post[maxn], in[maxn];
int num = 0;
int n;
struct node {
	int data;
	node *left;
	node *right;
};
//ÖÐÐò+ºóÐò½¨Ê÷
node* create(int postL,int postR,int inL,int inR) {
	if (postL > postR) {
		return NULL;
	}
	node *root = new node;
	root->data = post[postR];
	int k = -1;
	for (int i = inL; i <= inR;i++) {
		if (in[i] == post[postR]) {
			k = i;
			break;
		}
	}
	int num_left = k - inL;
	root->left = create(postL, postL + num_left - 1, inL, k - 1);
	root->right = create(postL + num_left, postR - 1, k + 1 , inR);
	return root;
}
void bfs(node *root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node *now = q.front();
		q.pop();
		cout << now->data;
		num++;
		if (num < n) cout << " ";
		if (now->left != NULL) q.push(now->left);
		if (now->right != NULL) q.push(now->right);
	}
}
int main() {
	node *root;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n;i++) {
		cin >> in[i];
	}
	root = create(0, n - 1, 0, n - 1);
	bfs(root);
	return 0;
}