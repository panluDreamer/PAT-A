#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int value;
	int left;
	int right;
};
const int maxn = 200;
node tree[maxn];
int buf[maxn] = { 0 };
int index = 0;
vector<int> ans;
bool cmp(int &a, int &b) {
	return a < b;
}
void inorder(int root) {
	if (root == -1) {
		return;
	}
	inorder(tree[root].left);
	tree[root].value = buf[index++];
	inorder(tree[root].right);
}
void levelOrder(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		ans.push_back(tree[front].value);
		if (tree[front].left != -1) {
			q.push(tree[front].left);
		}
		if (tree[front].right != -1) {
			q.push(tree[front].right);
		}
	}
}
int main() {
	int n, left, right;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> left >> right;
		tree[i].left = left;
		tree[i].right = right;
	}
	for (int i = 0; i < n;i++) {
		cin >> buf[i];
	}
	sort(buf, buf + n, cmp);
	inorder(0);
	levelOrder(0);
	int size = ans.size();
	for (int i = 0; i < size;i++) {
		cout << ans[i];
		if (i != size - 1) {
			cout << " ";
		}
	}
}