#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1010;
vector<int> Adj[maxn];
int layer[maxn] = { -1 };
bool inq[maxn] = { false };
queue<int> q;
void bfs(int u) {
	layer[u] = 0;
	q.push(u);
	inq[u] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		//inq[front] = true;
		//cout << "front:" << front << ": ";
		for (int i = 0; i < Adj[front].size(); i++) {
			if (inq[Adj[front][i]] == false) {
				//cout << "size = " << Adj[front].size() << endl;
			//	cout << Adj[front][i] << " ";
				layer[Adj[front][i]] = layer[front] + 1;
				q.push(Adj[front][i]);
				inq[Adj[front][i]] = true;
			}
		}
		//	cout << endl;
	}
}
int main() {
	int n, l;
	cin >> n >> l;
	int num, id;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> id;
			Adj[id].push_back(i);
		}
	}
	int times, query_id;
	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> query_id;
		bfs(query_id);
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if ((layer[i] >= 1) && (layer[i] <= l)) {
				count++;

			}
			//	cout << layer[i] << " ";
				//cout << layer[i] << " ";//怎么当query_id=6时，layer[2]=0呢，应该为-1啊，但是oj通过
		}
		for (int i = 0; i <= n; i++) {
			layer[i] = -1;
			inq[i] = false;
		}
		//	cout << endl;
		cout << count << endl;
	}
}