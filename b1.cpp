#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;//Ð¡¶¥¶Ñ
const int maxn = 1010;
vector<int> adj[maxn];
int indegree[maxn];
vector<int> order;
int n, m;
void check() {
	for (int i = 0; i < n;i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int front = q.top();
		q.pop();
		order.push_back(front);
		for (int u = 0; u < adj[front].size();u++) {
			int id = adj[front][u];
			indegree[id]--;
			if (indegree[id] == 0) {
				q.push(id);
			}
		}
		adj[front].clear();
	}
}

int main() {
	fill(indegree, indegree + maxn, 0);
	cin >> n >> m;
	int st, en;
	for (int i = 0; i < m;i++) {
		cin >> st >> en;
		adj[st].push_back(en);
		indegree[en]++;
	}
	check();
	int size = order.size();
	if (size == n) {
		cout << "YES" << endl;
		for (int i = 0; i < size;i++) {
			cout << order[i];
			if (i != size - 1) {
				cout << " ";
			}
			else {
				cout << endl;
			}
		}
	}
	else {
		cout << "NO" << endl;
		cout << n - size << endl;
	}
}


