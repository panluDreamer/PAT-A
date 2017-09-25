#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
map<string, int> nameToId;
map<int, string>idToName;
int num_city = 0;
const int maxn = 220;
const int inf = 1000000000;
int G[maxn][maxn] = { inf };
int happy[maxn];
bool visit[maxn] = { false };
vector<int> pre[maxn];
int d[maxn] = { inf };
vector<int> path, tempPath;
int pathNum = 0, cost = 0, maxHappy = 0, avgHappy = 0;
int change(string name) {
	if (nameToId.find(name) != nameToId.end()) {
		return nameToId[name];
	}
	else {
		nameToId[name] = num_city;
		idToName[num_city] = name;
		num_city++;
		return nameToId[name];
	}
}
void Dij(int s) {
	fill(d, d + maxn, inf);
	d[s] = 0;
	for (int i = 0; i < num_city; i++) {
		int u = -1, min = inf;
		for (int j = 0; j < num_city; j++) {
			if (visit[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;
		visit[u] = true;
		for (int v = 0; v < num_city; v++) {
			if (G[u][v] != inf&&visit[v] == false) {
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
void dfs(int e, int s) {
	if (e == s) {
		tempPath.push_back(s);
		pathNum++;
		int tempCost = 0;
		for (int i = tempPath.size() - 1; i > 0; i--) {
			int id1 = tempPath[i];
			int id2 = tempPath[i - 1];
			tempCost += G[id1][id2];
		}
		cost = tempCost;
		int tempHappy = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			tempHappy += happy[tempPath[i]];
		}
		if (tempHappy > maxHappy) {
			maxHappy = tempHappy;
			path = tempPath;
			avgHappy = tempHappy / (tempPath.size() - 1);
		}
		else if (tempHappy == maxHappy) {
			int tempAvg = tempHappy / (tempPath.size() - 1);
			//	cout << "tempAvg = " << tempAvg << endl;
			if (tempAvg > avgHappy) {
				avgHappy = tempAvg;
				maxHappy = tempHappy;
				path = tempPath;
			}
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(e);
	for (int i = 0; i < pre[e].size(); i++) {
		dfs(pre[e][i], s);
	}
	tempPath.pop_back();
}
int main() {
	fill(G[0], G[0] + maxn*maxn, inf);
	int n, k;
	string st;
	string name;
	int ha;
	cin >> n >> k >> st;
	int id;
	id = change(st);
	happy[id] = 0;
	for (int i = 1; i < n; i++) {
		cin >> name >> ha;
		happy[change(name)] = ha;
	}
	string s, e;
	int c, id_s, id_e;
	for (int i = 0; i < k; i++) {
		cin >> s >> e >> c;
		id_s = change(s);
		id_e = change(e);
		G[id_s][id_e] = c;
		G[id_e][id_s] = c;
	}
	/*for (int i = 0; i < num_city; i++) {
		for (int j = 0; j < num_city; j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	cout << "happy:" << endl;
	for (int i = 0; i < num_city; i++) {
		cout << happy[i] << " ";
	}*/
	Dij(nameToId[st]);
	dfs(nameToId["ROM"], nameToId[st]);
	//	cout << endl;
		/*cout << "d[]";
		for (int k = 0; k < num_city;k++) {
			cout << d[k] << " ";
		}
		cout << endl;*/
		/*cout << "pre:";
		for (int i = 0; i < num_city; i++) {
			for (int j = 0; j < pre[i].size(); j++) {
				cout << pre[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	cout << pathNum << " " << cost << " " << maxHappy << " " << avgHappy << endl;
	for (int i = path.size() - 1; i > 0; i--) {
		cout << idToName[path[i]] << "->";
	}
	cout << idToName[path[0]] << endl;
}