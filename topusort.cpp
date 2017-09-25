#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 110;
vector<int> adj[maxn];
int indegree[maxn];
int n, m;
int num = 0;
bool isLegal() {
	queue<int>q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		num++;
		for (int u = 0; u < adj[front].size(); u++) {
			int id = adj[front][u];
			indegree[id]--;
			if (indegree[id] == 0) {
				q.push(id);
			}
		}
		adj[front].clear();
	}
	if (num == n) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int s, t;
	fill(indegree, indegree + maxn, 0);
	while (cin >> n >> m) {
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < m; i++) {
			cin >> s >> t;
			adj[s].push_back(t);
			indegree[t]++;
		}
		if (isLegal()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		for (int i = 0; i < n;i++) {
			adj[i].clear();
		}
	}
	
}