#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct node {
	int id;
	int data;
	int left;
	int right;
};
const int maxn = 1020;
node buf[maxn];
int d[maxn];
int n;
int t = 0;
int full_layer = 0, max_layer = 0;
int node_count = 0;
bool cmp(int a,int b) {
	return a < b;
}
void get_layer(int n) {
	int pre = -1, now = 0;
	for (int i = 0; i < 20;i++) {
		int cur = pow(2.0, i + 1) - 1;
		int next = pow(2.0, i + 2) - 1;
		if (n == cur) {//刚好铺满每一层
			pre = now = i;
			break;
		}
		else if (n > cur&&n < next) {//最后一层没铺满
			pre = i;
			now = i + 1;
			break;
		}
	}
	full_layer = pre;
	max_layer = now;
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		node_count++;
		cout << buf[front].data;
		if (node_count != n) {
			cout << " ";
		}
		
		if (buf[front].left != -1) {
			q.push(buf[front].left);
		}
		if (buf[front].right != -1) {
			q.push(buf[front].right);
		}
	}

}
void inorder(int u) {
	if (u == -1) {
		return;
	}
	inorder(buf[u].left);
	buf[u].data = d[t++];
	inorder(buf[u].right);
}
int main() {

	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n;i++) {
		buf[i].data = -1;
		buf[i].id = i;
		buf[i].left = -1;
		buf[i].right = -1;
	}
	get_layer(n);
	//cout << "full_layer = " << full_layer << " max_layer = " << max_layer << endl;
	//create structure
	if (full_layer != max_layer) {


		int c1 = pow(2.0, full_layer + 1) - 1 - pow(2.0, full_layer);
		int c2 = pow(2.0, full_layer);
		int index = 1;
		for (int i = 0; i < c1; i++) {
			buf[i].left = index++;
			buf[i].right = index++;
		}
		for (int i = c1; i < c1 + c2; i++) {
			buf[i].left = index++;
			if (index == n) {
				break;
			}
			buf[i].right = index++;
			if (index == n) {
				break;
			}
		}
		sort(d, d + n, cmp);
		inorder(0);
		bfs(0);
		//cout << "node_count = " << node_count << endl;
	}
	else {
		//cout << "complete" << endl;
		int index = 1;
		int c1 = pow(2.0, full_layer + 1) - 1 - pow(2.0, full_layer);
		for (int i = 0; i < c1; i++) {
			buf[i].left = index++;
			buf[i].right = index++;
		}
		sort(d, d + n, cmp);
		inorder(0);
		bfs(0);
		//cout << "node_count = " << node_count << endl;
	}
}