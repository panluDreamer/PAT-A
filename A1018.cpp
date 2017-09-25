#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 520;
const int inf = 0x7fffffff;
int G[maxn][maxn];
int bike[maxn] = { 0 };
int d[maxn];
bool visit[maxn] = { false };
vector<int> pre[maxn];
vector<int>tempPath, path;
int n, cmax;
int need = inf, back = inf;
void Dij(int st) {
	fill(d, d + maxn, inf);
	d[st] = 0;
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
		for (int v = 1; v <= n; v++) {//一定要注意编号是1~n,所以v从1开始，而不是0
			if (visit[v] == false && G[u][v] != inf) {
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
void dfs(int en, int st) {
	if (en == st) {
		tempPath.push_back(st);
		//cout << "dfs" << endl;
		int tempNodeNum = tempPath.size() - 1;
		int tempBikeAim = tempNodeNum*cmax / 2;
		int tempSum = 0;
		int tempNeed = 0, tempBack = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			tempSum += bike[tempPath[i]];
		}
		if (tempSum > tempBikeAim) {
			tempBack = tempSum - tempBikeAim;
		}
		else {
			tempNeed = tempBikeAim - tempSum;
		}
		if (tempNeed != 0 && tempBack == 0) {
			if (tempNeed < need) {
				path = tempPath;
				need = tempNeed;
				back = 0;
			}
		}
		else if (tempNeed == 0 && tempBack != 0) {
			if (tempBack < back) {
				path = tempPath;
				back = tempBack;
				need = 0;
			}
		}
		else {
			need = 0;
			back = 0;
			path = tempPath;
		}
		/*if (flag == 0) {
			back = 0;
			tempNeed = tempBikeAim - tempSum;
			if (tempNeed < need) {
				path = tempPath;
				need = tempNeed;
			}
		}
		else if (flag == 1) {
			need = 0;
			tempBack = tempSum - tempBikeAim;
			if (tempBack < back) {
				back = tempBack;
				path = tempPath;
			}
		}*/
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
	fill(G[0], G[0] + maxn*maxn, inf);
	int sp, m;
	cin >> cmax >> n >> sp >> m;
	for (int i = 1; i <= n; i++) {
		cin >> bike[i];
	}
	int id1, id2, dis;
	for (int i = 1; i <= m; i++) {
		cin >> id1 >> id2 >> dis;
		G[id1][id2] = dis;
		G[id2][id1] = dis;
	}
	Dij(0);
	dfs(sp, 0);
	cout << need << " ";
	for (int i = path.size() - 1; i > 0; i--) {
		cout << path[i] << "->";
	}
	cout << path[0] << " " << back << endl;
	return 0;
}