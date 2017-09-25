#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 110;
struct node {
	int weight;
	vector<int>child;
};
node tree[maxn];
int n, m, s;
vector<int> path;
vector<int> temp;
bool cmp(int a, int b) {
	return tree[a].weight > tree[b].weight;
}
void dfs(int id, int sum) {
	if (sum == s) {
		//cout << "sum = " << sum << endl;
		if (tree[id].child.size() == 0) {
			int len = path.size();
			for (int i = 0; i < len - 1; i++) {
				cout << tree[path[i]].weight << " ";
			}
			cout << tree[path[len - 1]].weight << endl;
			//path.clear();
			return;
		}
		else {
			return;
		}
	}
	if (sum > s) {
		return;
	}
	for (int i = 0; i < tree[id].child.size(); i++) {
		int child = tree[id].child[i];
		path.push_back(child);
		dfs(child, sum + tree[child].weight);
		path.pop_back();
	}
}
int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		cin >> tree[i].weight;
	}
	int id1, k, id2;
	for (int i = 0; i < m; i++) {
		cin >> id1 >> k;
		for (int j = 0; j < k; j++) {
			cin >> id2;
			tree[id1].child.push_back(id2);
		}
		sort(tree[id1].child.begin(), tree[id1].child.end(), cmp);
	}
	/*	cout << "init" << endl;
		for (int i = 0; i < n;i++) {
			cout << i << ": ";
			for (int j = 0; j < tree[i].child.size();j++) {
				cout << tree[i].child[j] << " ";
			}
			cout << endl;
		}*/
	path.push_back(0);
	dfs(0, tree[0].weight);
	return 0;
}