#include<iostream>
#include<vector>
using namespace std;
const int maxn = 110;
vector<int> node[maxn];
int n, m;
int depth_max = -1;
int leaf_node[maxn] = { 0 };
void dfs(int index, int depth) {
	int size = node[index].size();
	if (size == 0) {
		leaf_node[depth]++;
	}
	if (depth > depth_max) {
		depth_max = depth;
	}
	for (int i = 0; i < node[index].size();i++) {
		int child = node[index][i];
		dfs(child, depth + 1);
	}
	
	
}
int main() {
	cin >> n >> m;
	int k, child, id;
	for (int i = 0; i < m; i++) {
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> child;
			node[id].push_back(child);
		}
	}
	dfs(1, 0);
	cout << leaf_node[0];
	for (int i = 1; i <= depth_max;i++) {
		cout << " " << leaf_node[i];
	}
	cout << endl;
}