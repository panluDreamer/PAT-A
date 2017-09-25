#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 10010;
bool visit[maxn] = { false };
bool inqueue[maxn] = { false };
vector<int>graph[maxn];
vector<int>ans;
int component = 0;
int n;
int layer[maxn] = { 0 };
int max_layer = -1;
struct type {
	int root;
	int max_height;
};
type value[maxn];//记录从每个点形成的最大树高
bool cmp(type& a, type& b) {
	return a.max_height > b.max_height;
}
void dfs(int u) {
	visit[u] = true;
	int size = graph[u].size();
	for (int v = 0; v < size; v++) {
		if (visit[graph[u][v]] == false) {
			dfs(graph[u][v]);
		}

	}
}
void bfs(int u) {
	queue<int> q;
	max_layer = -1;
	fill(inqueue, inqueue + maxn, false);
	fill(layer, layer + maxn, 0);
	q.push(u);
	inqueue[u] = true;
	layer[u] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (layer[front] > max_layer) {
			max_layer = layer[front];
		}
		//cout << "d";
		for (int v = 0; v < graph[front].size(); v++) {
			if (inqueue[graph[front][v]] == false) {
				layer[graph[front][v]] = layer[front] + 1;
				q.push(graph[front][v]);
				inqueue[graph[front][v]] = true;
			}
		}
	}
}
void dfsGraph() {
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			component++;
			dfs(i);
		}
	}
}
int main() {
	cin >> n;
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfsGraph();
	if (component != 1) {
		cout << "Error: " << component << " components" << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			//max_layer = -1;
			//cout << "i=" << i << endl;
			bfs(i);
			value[i].max_height = max_layer;
			value[i].root = i;
			//	cout << endl;
			//	cout << "max_layer = " << max_layer << endl;
		}
		//	for (int i = 1; i <=n;i++) {
			//	cout << value[i].root << ": "<<value[i].max_height<<" ";
		//	}
		//cout << endl;
		sort(value + 1, value + n + 1, cmp);
		//for (int i = 1; i <= n; i++) {
		//	cout << value[i].root << ": "<<value[i].max_height<<" ";
		//}
		set<int> ans;
		int pre = 1;
		ans.insert(value[pre].root);
		for (int i = 2; i <= n; i++) {
			if (value[i].max_height == value[pre].max_height) {
				ans.insert(value[i].root);
			}
			else {
				break;
			}
		}
		set<int>::iterator it;
		for (it = ans.begin(); it != ans.end(); it++) {
			cout << *it << endl;
		}

	}
}