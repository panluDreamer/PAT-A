#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int G[maxn][maxn];//1~n
int inq[maxn] = { false };
int n, l;
int layer[maxn];
void bfs(int s, int &count) {
	fill(layer, layer + maxn, 0);
	fill(inq, inq + maxn, false);
	queue<int> q;
	q.push(s);
	inq[s] = true;
	layer[s] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (layer[front] > 0 && layer[front] <= l) {
			count++;
		}
		if (layer[front] > l) {
			break;
		}
		for (int v = 1; v <= n; v++) {
			if (inq[v] == false && G[front][v] != 0) {
				layer[v] = layer[front] + 1;
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

int main() {
	fill(G[0], G[0] + maxn*maxn, 0);
	fill(inq, inq + maxn, false);
	cin >> n >> l;
	int num, temp;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> temp;
			G[temp][i] = 1;
		}
	}
	int k, id, count;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> id;
		count = 0;
		bfs(id, count);
		cout << count << endl;
	}
}