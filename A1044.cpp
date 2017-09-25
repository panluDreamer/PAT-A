#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct node {
	int i;
	int j;
};
const int maxn = 100010;
int buf[maxn];
int n, m;
vector<node> ans;
int main() {
	scanf("%d%d", &n, &m);//输入比cin快,暴力法求解会有4分超时
	for (int i = 1; i <= n; i++) {
		scanf("%d", &buf[i]);
	}
	int min_gap = 10000000;
	node temp_node;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int j = i;
		while (j <= n) {
			sum += buf[j];
			if (sum >= m) {
				int temp = sum - m;
				temp_node.i = i;
				temp_node.j = j;
				if (temp < min_gap) {
					ans.clear();
					ans.push_back(temp_node);
					min_gap = temp;//更新
				}
				else if (temp == min_gap) {
					ans.push_back(temp_node);
				}
				break;
			}
			else {//<m
				j++;
			}
		}
	}
	int size = ans.size();
	for (int i = 0; i < size; i++) {
		//cout << ans[i].i << "-" << ans[i].j << endl;
		printf("%d-%d\n", ans[i].i, ans[i].j);
	}
}