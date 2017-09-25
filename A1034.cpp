#include<iostream>
#include<map>
#include<string>
using namespace std;
const int maxn = 2010;
int G[maxn][maxn] = { 0 };
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;
int n, k, numPerson = 0;
int weight[maxn] = { 0 };
bool visit[maxn] = { false };
int change(string name) {
	if (stringToInt.find(name) != stringToInt.end()) {//already exist
		return stringToInt[name];
	}
	else {
		stringToInt[name] = numPerson;
		intToString[numPerson] = name;
		numPerson++;
		return stringToInt[name];
	}
}
void dfs(int u, int &sum, int &num, int &head) {
	num++;
	visit[u] = true;
	if (weight[u] > weight[head]) {
		head = u;
	}
	for (int i = 0; i < numPerson; i++) {
		if (G[u][i] > 0) {
			sum += G[u][i];
			G[u][i] = G[i][u] = 0;//删除访问过的边，因为图中可能有环
			if (visit[i] == false) {//当节点i未被访问时
				dfs(i, sum, num, head);
			}
		}
	}
}
void dfsGraph(int u) {
	int sum, num, head;
	for (int i = 0; i < numPerson; i++) {
		if (visit[i] == false) {
			head = i;
			sum = 0;
			num = 0;
			dfs(i, sum, num, head);
			//cout << "sum = " << sum << " num = " << num << " head=" << head << endl;
			if (num > 2 && sum > k) {
				ans[intToString[head]] = num;
				//cout << "here" << endl;
			}
		}
	}
}
int main() {
	cin >> n >> k;
	string a, b;
	int time;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> time;
		int id1 = change(a);
		int id2 = change(b);
		weight[id1] += time;
		weight[id2] += time;
		G[id1][id2] += time;
		G[id2][id1] += time;
	}
	dfsGraph(0);
	cout << ans.size() << endl;
	map<string, int>::iterator it;
	for (it = ans.begin(); it != ans.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}