#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<iomanip>
using namespace std;
const int maxn = 100010;
vector<int> tree[maxn];
int layer[maxn] = { -1 };
queue<int> q;
void bfs(int root) {
	q.push(root);
	layer[root] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < tree[front].size(); i++) {
			q.push(tree[front][i]);
			layer[tree[front][i]] = layer[front] + 1;
		}
	}
}
int main() {
	int n;
	double p, r;
	cin >> n >> p >> r;
	double rate = 1 + r / 100;
	int temp, root;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp != -1) {
			tree[temp].push_back(i);
		}
		else {
			root = i;
		}
	}
	bfs(root);
	int maxLayer = -1;
	for (int i = 0; i < n; i++) {
		if (layer[i] > maxLayer) {
			maxLayer = layer[i];
		}
	}
	int count = 0;
	double price;
	price = p*pow(rate, maxLayer);
	for (int i = 0; i < n; i++) {
		if (layer[i] == maxLayer) {
			count++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << price << " ";
	cout << count;
	return 0;
}