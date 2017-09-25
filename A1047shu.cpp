#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 40010;
const int maxk = 2510;
char stu[maxn][5];
vector<int> course[maxk];
bool cmp(int &a, int &b) {
	return strcmp(stu[a], stu[b]) < 0;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int num, temp;
	for (int i = 0; i < n; i++) {
		scanf("%s %d", &stu[i], &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &temp);
			course[temp].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++) {
		int size = course[i].size();
		sort(course[i].begin(), course[i].end(), cmp);
		printf("%d %d\n", i, size);
		for (int j = 0; j < size; j++) {
			printf("%s\n", stu[course[i][j]]);
		}
	}
}