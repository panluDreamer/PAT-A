#include<iostream>
#include<vector>
#include<set>
#include<iostream>
using namespace std;
const int maxn = 510;
const int inf = 100000000;
struct city {
	int len;
	int id;
};
vector<city> g[maxn];
int rescue[maxn];
int n, m, c1, c2;
int d[maxn];
set<int> pre[maxn];
vector<int> path;
vector<int> temp_path;
int path_num = 0;
int max_rescue = -1;
void bellman_ford(int s) {
	fill(d, d + maxn, inf);
	d[s] = 0;
	for (int i = 0; i < n - 1; i++) {//n-1轮
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < g[u].size(); j++) {
				int v = g[u][j].id;
				if (d[u] + g[u][j].len < d[v]) {
					d[v] = d[u] + g[u][j].len;
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (d[u] + g[u][j].len == d[v]) {
					pre[v].insert(u);
				}
			}
		}
	}
}
bool check() {
	for (int u = 0; u < n; u++) {
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j].id;
			if (d[u] + g[u][j].len < d[v]) {
				return true;
			}
		}
	}
	return false;
}
void dfs(int st, int v) {
	//cout << "dfs" << endl;
	if (st == v) {
		//cout << "here" << endl;
		temp_path.push_back(st);
		path_num++;
		int size = temp_path.size();
		int temp_sum = 0;
		for (int i = size - 1; i >= 0; i--) {
			int id = temp_path[i];
			temp_sum += rescue[id];
		}
		if (temp_sum > max_rescue) {
			max_rescue = temp_sum;
			path = temp_path;
		}
		temp_path.pop_back();
		return;
	}
	//cout << "v:" << v << endl;
	temp_path.push_back(v);
	set<int>::iterator it;
	for (it = pre[v].begin(); it != pre[v].end(); it++) {
		dfs(st, *it);
	}
	temp_path.pop_back();
}
int main() {
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		cin >> rescue[i];
	}
	int st, en, len;
	city temp;
	for (int i = 0; i < m; i++) {
		cin >> st >> en >> len;
		temp.id = en;
		temp.len = len;
		g[st].push_back(temp);
		temp.id = st;
		temp.len = len;
		g[en].push_back(temp);
	}
	bellman_ford(c1);
	int flag = check();//检查是否存在负环
	//cout << "flag = " << flag << endl;
	dfs(c1, c2);
	cout << path_num << " " << max_rescue << endl;
	/*int size = path.size();
	for (int i = size - 1; i >= 0;i--) {
		cout << path[i] << " ";
	}*/
}