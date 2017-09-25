#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxv = 510;
const int inf = 1000000000;
bool visit[maxv] = { false };
int n;
struct node {
	int len;
	int time;
};
node G[maxv][maxv];
int d[maxv];
int t[maxv];
vector<int> pre[maxv];
vector<int> temp_path;
vector<int> ans;
vector<int> time_pre[maxv];
vector<int> time_temp;
vector<int> time_ans;
int ans_time = inf;
int node_count = inf;
void Dij_len(int s) {
	fill(d, d + maxv, inf);
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
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && G[u][v].len != -1) {
				if (d[u] + G[u][v].len < d[v]) {
					d[v] = d[u] + G[u][v].len;
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v].len == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
void dfs_len(int st, int v) {
	if (st == v) {
		temp_path.push_back(st);
		int temp_time = 0;
		for (int i = temp_path.size() - 1; i > 0; i--) {
			int curr = temp_path[i];
			int next = temp_path[i - 1];
			temp_time += G[curr][next].time;//¿€º”!!!!!!
		}
		if (temp_time < ans_time) {
			ans = temp_path;
			ans_time = temp_time;
		}
		temp_path.pop_back();
		return;
	}
	temp_path.push_back(v);
	for (int j = 0; j < pre[v].size(); j++) {
		dfs_len(st, pre[v][j]);
	}
	temp_path.pop_back();
}
void Dij_time(int s) {
	fill(t, t + maxv, inf);
	fill(visit, visit + maxv, false);
	t[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, min = inf;
		for (int j = 0; j < n; j++) {
			if (visit[j] == false && t[j] < min) {//t[j],not d[j]
				min = t[j];
				u = j;
			}
		}
		if (u == -1) return;
		visit[u] = true;
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && G[u][v].time != -1) {
				if (t[u] + G[u][v].time < t[v]) {
					t[v] = t[u] + G[u][v].time;
					time_pre[v].clear();
					time_pre[v].push_back(u);
				}
				else if (t[u] + G[u][v].time == t[v]) {
					time_pre[v].push_back(u);
				}
			}
		}
	}
}
void dfs_time(int st, int v) {
	if (st == v) {
		time_temp.push_back(st);
		if (time_temp.size() < node_count) {
			time_ans = time_temp;
			node_count = time_temp.size();
		}
		time_temp.pop_back();
		return;
	}
	time_temp.push_back(v);
	for (int j = 0; j < time_pre[v].size(); j++) {
		dfs_time(st, time_pre[v][j]);
	}
	time_temp.pop_back();
}
int main() {
	int m;
	cin >> n >> m;
	for (int i = 0; i < maxv; i++) {
		for (int j = 0; j < maxv; j++) {
			G[i][j].len = -1;
			G[i][j].time = -1;
		}
	}
	int v1, v2, one_way, length, time;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> one_way >> length >> time;
		G[v1][v2].len = length;
		G[v1][v2].time = time;
		if (one_way == 0) {
			G[v2][v1].len = length;
			G[v2][v1].time = time;
		}
	}
	int st, en;
	cin >> st >> en;
	Dij_len(st);
	dfs_len(st, en);
	Dij_time(st);
	dfs_time(st, en);
	int size = ans.size();
	int total = 0;
	for (int i = size - 1; i > 0; i--) {
		int curr = ans[i];
		int next = ans[i - 1];
		//	cout << next << "->" << curr << ":";
		//cout << "len = " << G[next][curr].len << endl;
		total += G[curr][next].len;
		//cout << "dis=" << total<< endl;
	}
	//cout << "dis = " << total << endl;
	int time_size = time_ans.size();
	int total_time = 0;
	for (int i = time_size - 1; i > 0; i--) {
		int curr = time_ans[i];
		int next = time_ans[i - 1];
		total_time += G[curr][next].time;
	}
	//cout << "time = " << total_time << endl;
	cout << "Distance = " << total;
	if (ans == time_ans) {
		cout << "; ";
	}
	else {
		cout << ": ";
		for (int i = size - 1; i >= 0; i--) {
			cout << ans[i];
			if (i != 0) {
				cout << " -> ";
			}
		}
		cout << endl;
	}
	cout << "Time = " << total_time << ": ";
	for (int i = time_size - 1; i >= 0; i--) {
		cout << time_ans[i];
		if (i != 0) {
			cout << " -> ";
		}
	}
}