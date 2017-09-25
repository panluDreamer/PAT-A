#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int i;
	int j;
};
int n, m;
const int maxn = 100010;
const int inf = 1000000000;
int buf[maxn];
int s[maxn] = { 0 };
vector<node> ans1;
vector<node> ans2;
int lower_bounds(int left, int right, int x) {//找到第一个>=x的位置
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (s[mid] >= x) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}
int main() {
	int min_near = inf;
	scanf("%d%d", &n, &m);
	fill(s, s + maxn, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &buf[i]);
		s[i + 1] = s[i] + buf[i];
	}
	node temp;
	for (int i = 1; i <= n; i++) {
		int sum = s[i - 1] + m;
		int j;
		//j = lower_bound(s+i, s+n + 1, sum)-s;//使用头文件下面的lower_bound()函数
		j = lower_bounds(i, n + 1, sum);//二分区间为i到n+1
		//printf("i=%d,j=%d\n", i,j);
		if (j <= n&&s[j] == s[i - 1] + m) {//find
			//printf("i=%d,j=%d\n", i, j);
			temp.i = i;
			temp.j = j;
			ans1.push_back(temp);
		}
		else {
			//printf("i=%d,j=%d\n", i, j);
			if (j <= n&&s[j] - s[i - 1] < min_near) {
				ans2.clear();
				temp.i = i;
				temp.j = j;
				ans2.push_back(temp);
				min_near = s[j] - s[i - 1];
			}
			else if (j <= n&&s[j] - s[i - 1] == min_near) {
				temp.i = i;
				temp.j = j;
				ans2.push_back(temp);
			}
		}
	}
	int size1 = ans1.size();
	int size2 = ans2.size();
	if (size1 != 0) {
		for (int i = 0; i < size1; i++) {
			printf("%d-%d\n", ans1[i].i, ans1[i].j);
		}
	}
	else {
		for (int i = 0; i < size2; i++) {
			printf("%d-%d\n", ans2[i].i, ans2[i].j);
		}
	}
}
