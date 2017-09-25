#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 12;
struct node {
	int left;
	int right;
};
vector<int> level_ans;
vector<int> in_ans;
node tree[maxn];
bool hashTable[maxn] = { false };
int n;
void init() {
	for (int i = 0; i < maxn;i++) {
		tree[i].left = -1;
		tree[i].right = -1;
	}
}
void level_order(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		level_ans.push_back(front);
		if (tree[front].right != -1) {
			q.push(tree[front].right);
		}
		if (tree[front].left != -1) {
			q.push(tree[front].left);
		}
	}
}
void inOrder(int root) {
	if (root == -1) {
		return;
	}
	inOrder(tree[root].right);
	in_ans.push_back(root);
	inOrder(tree[root].left);
}
int main() {
	int n;
	cin >> n;
	init();
	char left, right;
	for (int i = 0; i < n;i++) {
		cin >> left >> right;
		if (left != '-') {
			tree[i].left = left - '0';
			hashTable[left - '0'] = true;
		}
		if (right != '-') {
			tree[i].right = right - '0';
			hashTable[right - '0'] = true;
		}
	}
	//find root
	int root;
	for (int i = 0; i < n;i++) {
		if (hashTable[i] == false) {
			root = i;
			break;
		}
	}
	level_order(root);
	inOrder(root);
	for (int i = 0; i < n;i++) {
		cout << level_ans[i];
		if (i != n - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
	for (int i = 0; i < n;i++) {
		cout << in_ans[i];
		if (i != n - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
}