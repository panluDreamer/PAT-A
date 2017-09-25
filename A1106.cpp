#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<iomanip>
using namespace std;
const int maxn = 100010;
const int inf = 0x7fffffff;
vector<int> tree[maxn];
bool retail[maxn] = { false };
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
	int k, temp;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 0) {
			retail[i] = true;
		}
		else {
			for (int j = 0; j < k; j++) {
				cin >> temp;
				tree[i].push_back(temp);
			}
		}
	}
	bfs(0);
	int minLay = inf;
	for (int i = 0; i < n; i++) {
		if (layer[i] < minLay&&retail[i]) {
			minLay = layer[i];
		}
	}
	double price = p*pow(rate, minLay);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (layer[i] == minLay&&retail[i]) {
			count++;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(4) << price << " ";
	cout << count;
	return 0;
}