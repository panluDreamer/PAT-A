#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 520;
const int inf = 0x7fffffff;
int G[maxn][maxn];
int cost[maxn][maxn];
int d[maxn] = { inf };
bool visit[maxn] = { false };
vector<int> pre[maxn];
vector<int> tempPath, path;
int mindistance, mincost = inf;
int n;
void Dij(int st) {
	fill(d, d + maxn, inf);//£¡£¡£¡
	d[st] = 0;
	//visit[st] = true;
	for (int i = 0; i < n; i++) {
		int min = inf, u = -1;
		for (int j = 0; j < n; j++) {
			if (visit[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1) return;
		visit[u] = true;
		for (int j = 0; j < n; j++) {
			if (visit[j] == false && G[u][j] != inf) {
				//cout << "G[u][v] = " << G[u][j] << endl;
				if (d[u] + G[u][j] < d[j]) {
					d[j] = d[u] + G[u][j];
					pre[j].clear();
					pre[j].push_back(u);
					//	cout << "d[j]=" << d[j] << endl;
				}
				else if (d[u] + G[u][j] == d[j]) {
					pre[j].push_back(u);
					//	cout << "d[j]====" << d[j] << endl;
				}
			}
		}
	}
}
void dfs(int en, int st) {
	if (en == st) {
		tempPath.push_back(st);
		int tempCost = 0;
		int tempdis = 0;
		for (int i = tempPath.size() - 1; i > 0; i--) {
			int id = tempPath[i];
			int next = tempPath[i - 1];
			tempdis += G[id][next];
			tempCost += cost[id][next];
		}
		mindistance = tempdis;
		if (tempCost < mincost) {
			mincost = tempCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(en);
	for (int i = 0; i < pre[en].size(); i++) {
		dfs(pre[en][i], st);
	}
	tempPath.pop_back();
}
int main() {
	int m, s, d;
	cin >> n >> m >> s >> d;
	int id1, id2, dis, cos;
	fill(G[0], G[0] + maxn*maxn, inf);
	for (int i = 0; i < m; i++) {
		cin >> id1 >> id2 >> dis >> cos;
		G[id1][id2] = dis;
		G[id2][id1] = dis;
		cost[id1][id2] = cos;
		cost[id2][id1] = cos;
	}
	Dij(s);
	dfs(d, s);
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << mindistance << " " << mincost << endl;
	return 0;
}