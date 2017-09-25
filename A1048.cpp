//dfs 3，4测试点段错误,20points,dfs深度太深？
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int buf[100020];
bool cmp(int a, int b) {
	return a <= b;
}
int n, m;
vector<int> temp;
vector<vector<int>> all;
void dfs(int index, int now, int sum) {
	if (now == 2 && sum == m) {
		all.push_back(temp);
		return;
	}
	if (now > 2 || sum > m || index == n) return;
	temp.push_back(buf[index]);
	dfs(index + 1, now + 1, sum + buf[index]);
	temp.pop_back();
	dfs(index + 1, now, sum);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
	}
	sort(buf, buf + n);
	dfs(0, 0, 0);
	if (all.size() == 0) {
		cout << "No Solution";
	}
	else {
		//int len = all[0].size();
	  //	for (int i = 0; i < len - 1;i++) {
		//	cout << all[0][i] << " ";
	//	}
		cout << all[0][0] << " " << all[0][1];
		//cout << all[0][len - 1];
	}
}