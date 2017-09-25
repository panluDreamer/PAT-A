#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int n, k, p;
vector<int> d;
vector<int> ans;
vector<int> temp_ans;
int s;//d.size
int ans_factor_sum = 0;
void init() {
	for (int i = 1; i <= n; i++) {
		int temp = pow(1.0*i, p);
		if (temp > n) {
			break;
		}
		else {
			d.push_back(i);
		}
	}
}
void dfs(int index, int nowk, int sum) {
	if (nowk == k&&sum == n) {//need to compare
		int temp_factor_sum = 0;
		for (int i = 0; i < k; i++) {
			temp_factor_sum += d[temp_ans.at(i)];
		}
		if (temp_factor_sum > ans_factor_sum) {
			ans = temp_ans;
			ans_factor_sum = temp_factor_sum;//刚刚这里忘记更新，会有一个点过不去
		}
	}
	if (nowk > k || sum > n || index < 0) {
		return;
	}
	temp_ans.push_back(index);
	dfs(index, nowk + 1, sum + pow(1.0*d[index], p));
	temp_ans.pop_back();
	dfs(index - 1, nowk, sum);
}
int main() {
	cin >> n >> k >> p;
	init();
	s = d.size();
	dfs(s - 1, 0, 0);
	int size = ans.size();
	if (size == 0) {
		cout << "Impossible" << endl;
	}
	else {
		cout << n << " = ";
		for (int i = 0; i < size; i++) {
			cout << d[ans.at(i)] << "^" << p;
			if (i != size - 1) {
				cout << " + ";
			}
		}
		cout << endl;
	}
}