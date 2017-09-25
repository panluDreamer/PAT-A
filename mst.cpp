#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 100;
const int inf = 0x3fffffff;
int G[maxn][maxn];
int pre[maxn];
struct edge {
	int start;
	int end;
};
vector<edge> ans;
vector<int> node[maxn];
int n, m;
int d[maxn];
bool visit[maxn];
int mstSum = 0;
edge temp_edge;
void mst(int s) {
	fill(d, d + maxn, inf);
	fill(visit, visit + maxn, false);
	fill(pre, pre + maxn, -1);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, min = inf;
		for (int j = 0; j < n; j++) {
			if (visit[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;
		visit[u] = true;
		mstSum += d[u];
		temp_edge.start = pre[u];
		temp_edge.end = u;
		ans.push_back(temp_edge);
		for (int j = 0; j < n; j++) {
			if (visit[j] == false && G[u][j] != 0 && G[u][j] < d[j]) {
				d[j] = G[u][j];
				pre[j] = u;
			}
		}
	}
}
void level_mst(int s) {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		for (int i = 0; i < node[front].size(); i++) {
			q.push(node[front][i]);
		}
	}
}
int main() {
	fill(G[0], G[0] + maxn*maxn, 0);
	cin >> n >> m;
	int st, en, len;
	for (int i = 0; i < m; i++) {
		cin >> st >> en >> len;
		G[st][en] = len;
		G[en][st] = len;
	}
	mst(0);
	cout << "mst sum = " << mstSum << endl;
	int size = ans.size();
	for (int i = 0; i < size; i++) {
		cout << "edge" << i + 1 << ":" << ans[i].start << "---" << ans[i].end << endl;
	}
	//level order of mst
	for (int i = 1; i < size; i++) {
		node[ans[i].start].push_back(ans[i].end);
	}
	cout << "level order of mst:" << endl;
	level_mst(0);
}