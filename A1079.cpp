#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<iomanip>
using namespace std;
const int maxn = 100010;
vector<int> tree[maxn];
bool retail[maxn] = { false };
int amount[maxn] = { 0 };
int layer[maxn] = { -1 };
queue<int> q;
void bfs() {
	int index = 0;
	q.push(index);
	layer[index] = 0;
	while (!q.empty()) {
		int front = q.front();
		//	cout << "layer = " << layer[front] << " ";
		q.pop();
		for (int i = 0; i < tree[front].size(); i++) {
			q.push(tree[front][i]);
			layer[tree[front][i]] = layer[front] + 1;
		}
	}
}
int main() {
	int n;
	double p, r;
	//scanf("%d%lf%lf", &n, &p, &r);
	cin >> n >> p >> r;
	double rate = 1 + r / 100;
	int k, temp;
	for (int i = 0; i < n; i++) {
		//scanf("%d", &k);
		cin >> k;
		//printf("hehe");
		//cout << "hehe";
		if (k == 0) {
			retail[i] = true;
			//scanf("%d", &temp);
			cin >> temp;
			amount[i] = temp;
		}
		else {
			for (int j = 0; j < k; j++) {
				//scanf("%d", &temp);
				cin >> temp;
				tree[i].push_back(temp);
			}
		}
	}
	bfs();
	//for (int i = 0; i < n;i++) {
	//	printf("%d ", layer[i]);
	//	cout << layer[i] << " ";
	//}
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		if (retail[i]) {
			ans += amount[i] * p*pow(rate, layer[i]);
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1) << ans << endl;
}