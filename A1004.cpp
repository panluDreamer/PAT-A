#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 110;
vector<int> node[maxn];
int leaf_node[maxn];
int layer[maxn];
int n, m;
int max_layer = -1;
void bfs(int root) { 
	fill(leaf_node, leaf_node + maxn, -1);
	queue<int> q;
	q.push(root);
	layer[root] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		int lay = layer[front];
		if (lay > max_layer) {
			max_layer = lay;
		}
		int size = node[front].size();
		if (size == 0) {
			if (leaf_node[lay] == -1) {
				leaf_node[lay] = 1;
			}
			else {
				leaf_node[lay]++;
			}
		}
		for (int i = 0; i < size; i++) {
			int c = node[front][i];
			layer[c] = lay + 1;
			q.push(c);
		}
	}
}
int main() {
	cin >> n >> m;
	int k, child, id;
	for (int i = 0; i < m; i++) {
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> child;
			node[id].push_back(child);
		}
	}
	bfs(1);
	if (leaf_node[0] == -1) {
		cout << "0";
	}
	else {
		cout << leaf_node[0];
	}
	for (int i = 1; i <= max_layer; i++) {
		if (leaf_node[i] != -1) {
			cout << " " << leaf_node[i];
		}
		else {
			cout << " 0";
		}
	}
	cout << endl;
}
