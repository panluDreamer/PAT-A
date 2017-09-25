#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<iomanip>
using namespace std;
const int maxn = 110;
vector<int> tree[maxn];
int layer[maxn] = { -1 };
int layerNum[maxn] = { 0 };
int hashTable[maxn] = { 0 };
queue<int> q;
/*void dfs(int index,int level) {
	hashTable[level]++;
	for (int i = 0; i < tree[index].size();i++) {
		dfs(tree[index][i], level + 1);
	}
}*/
void bfs(int root) {
	layer[root] = 1;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < tree[front].size(); i++) {
			q.push(tree[front][i]);
			layer[tree[front][i]] = layer[front] + 1;
			//	cout << "tempLayer = " << layer[tree[front][i]] << " ";
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int id, k, temp;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &temp);
			tree[id].push_back(temp);
		}
	}
	bfs(1);
	int maxLayer = 0;
	for (int i = 1; i <= n; i++) {//节点1~n，而不是0~n-1,故应该是<=n，而不是<n
	//	cout << "layer" << i << " = " << layer[i] << endl;
		layerNum[layer[i]]++;
		if (layer[i] > maxLayer) {
			maxLayer = layer[i];
		}
	}
	//cout << "maxlayer = " << maxLayer << endl;
	/*for (int i = 1; i <= maxLayer+1;i++) {
		cout << layerNum[i] << " ";
	}
	cout << endl;*/
	int maxNum = -1, level = 0;
	for (int i = 1; i < maxn; i++) {
		if (layerNum[i] > maxNum) {
			maxNum = layerNum[i];
			level = i;
		}
	}
	//dfs(1, 1);
/*	for (int i = 1; i < maxn;i++) {
		if (hashTable[i] > maxNum) {
			maxNum = hashTable[i];
			level = i;
		}
	}*/
	printf("%d %d", maxNum, level);
	return 0;
}