#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1010;
int graph[maxn][maxn] = { 0 };
int copy_graph[maxn][maxn] = { 0 };
bool inqueue[maxn] = { false };
int n;
int ans = 0;
void bfs(int u) {
	queue<int> q;
	q.push(u);
	inqueue[u] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int v = 1; v <= n; v++) {
			if (inqueue[v] == false && copy_graph[front][v] != 0) {
				q.push(v);
				inqueue[v] = true;
			}
		}
	}
}
void bfsGraph() {
	//cout << "here n=" <<n<< endl;
	for (int i = 1; i <= n; i++) {
		//	cout << "i=" << i << endl;
		if (inqueue[i] == false) {
			ans++;
			bfs(i);
		}
	}
}
int main() {
	int m, k;
	cin >> n >> m >> k;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	int city;
	for (int i = 0; i < k; i++) {
		cin >> city;
		fill(inqueue, inqueue + maxn, false);
		fill(copy_graph[0], copy_graph[0] + maxn*maxn, 0);
		ans = 0;
		for (int i = 0; i <= n; i++) {//copy
			for (int j = 0; j <= n; j++) {
				copy_graph[i][j] = graph[i][j];
			}
		}
		for (int i = 0; i <= n; i++) {
			copy_graph[city][i] = 0;
			copy_graph[i][city] = 0;
		}
		/*	cout << "copy:" << endl;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << copy_graph[i][j] << " ";
				}
				cout << endl;
			}*/
		bfsGraph();
		cout << ans - 2 << endl;
	}
}