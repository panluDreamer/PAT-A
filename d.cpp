#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int inf = 0x3fffffff;
int G[maxn][maxn];
double funeng[maxn];
int n, m, l, k, s, t;
bool inq[maxn] = { false };
int layer[maxn] = { 0 };
int d[maxn];
vector<int> pre[maxn];
bool visit[maxn];
vector<int> path;
vector<int> tempPath;
int pathlen = 0;
int pathNum = 0;
int remain = -1;
int funengSum = inf;
void bfs(int u) {
	queue<int>q;
	q.push(u);
	inq[u] = true;
	layer[u] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		int temp_layer = layer[front];
		for (int v = 0; v < n; v++) {
			if (inq[v] == false && G[front][v] != -1) {
				q.push(v);
				layer[v] = temp_layer + 1;
				inq[v] = true;
			}
		}
	}
}
void Dij(int s) {
	fill(d, d + maxn, inf);
	fill(visit, visit + maxn, false);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		//cout << "h" << endl;
		int u = -1, min = inf;
		for (int j = 0; j < n; j++) {
			if (visit[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		//cout << "u = " << u << endl;
		if (u == -1) return;
		visit[u] = true;
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && G[u][v] != -1) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];

					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
void dfs(int s, int v) {
	if (s == v) {
		tempPath.push_back(s);
		pathNum++;
		int tempLen = 0;
		int tempSum = 0;
		int temp_remain;
		int size = tempPath.size();
		for (int i = size - 1; i > 0; i--) {
			int id = tempPath[i];
			int next = tempPath[i - 1];
			tempLen += G[id][next];
		}
		//cout << "templen = " << tempLen << endl;
		pathlen = tempLen;
		for (int i = size - 1; i >= 0; i--) {
			tempSum += funeng[tempPath[i]];
		}
		int tempfuneng = 0;
		int tm = size / 2;
		for (int j = 0; j < tm; j++) {
			tempfuneng += funeng[tempPath[j]];
		}
		//cout << "tempSum = " << tempSum << endl;
		temp_remain = tempSum%k;
		//cout << "temp_remain = " << temp_remain << endl;
		if (temp_remain > remain) {
			remain = temp_remain;
			path = tempPath;
			funengSum = tempfuneng;
		}
		else if (temp_remain == remain) {
			if (tempfuneng < funengSum) {
				funengSum = tempfuneng;
				path = tempPath;
				remain = temp_remain;
			}
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(s, pre[v][i]);
	}
	tempPath.pop_back();
}
int main() {
	cin >> n >> m >> l >> k >> s >> t;
	fill(G[0], G[0] + maxn*maxn, -1);
	for (int i = 0; i < n; i++) {
		cin >> funeng[i];
	}
	int id1, id2, len;
	for (int i = 0; i < m; i++) {
		cin >> id1 >> id2 >> len;
		G[id1][id2] = len;
		G[id2][id1] = len;
	}
	bfs(s);
	if (inq[t] == false) {
		cout << "-1" << endl;
		return 0;
	}
	/*for (int i = 0; i < n; i++) {
		cout << layer[i] << " ";
	}*/
	int curr_layer = layer[s];
	double ratio = 100, minus = 100 / l;
	int curr = 0;
	while (curr < l) {
		for (int i = 0; i < n; i++) {
			if (layer[i] == curr) {
				funeng[i] = funeng[i] + ceil(funeng[i] * ratio / 100);
			}
		}
		curr++;
		ratio -= minus;
	}
	/*cout << endl;
	for (int i = 0; i < n; i++) {
		cout << funeng[i] << " ";
	}*/
	Dij(s);
	dfs(s, t);
	cout << pathNum << " " << pathlen << " " << remain << " " << funengSum << endl;
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i];
		if (i != 0) {
			cout << "->";
		}
	}
}