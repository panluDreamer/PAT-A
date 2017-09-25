#include<iostream>
#include<vector>
using namespace std;
const int maxn = 25;
int max_value = 0;
int w[maxn];
int c[maxn];
int n, v;
vector<int> temp;
vector<int> ans;
void dfs(int index,int curr_wei,int curr_value) {
	if (index == n) {
		if (curr_value > max_value) {
			max_value = curr_value;
			ans = temp;
		}
		return;
	}
	dfs(index + 1, curr_wei, curr_value);//do not select
	if (curr_wei + w[index] <= v) {//小于背包最大承受重量
		temp.push_back(index);
		dfs(index + 1, curr_wei + w[index], curr_value + c[index]);
		temp.pop_back();
	}
}
int main() {
	cin >> n >> v;
	for (int i = 0; i < n;i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n;i++) {
		cin >> c[i];
	}
	dfs(0, 0, 0);
	cout << max_value<<endl;
	for (int i = 0; i < ans.size();i++) {
		cout << ans[i] << " ";
	}
}