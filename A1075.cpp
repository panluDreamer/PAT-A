/**
*PAT Judge 处理数据细节较繁杂,要注意节省时间
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxProb = 10;
const int maxUser = 10010;
struct user {
	int id;
	int grade[maxProb];
	int total;
	int perfect;
	bool flag;//标识是否有提交
};
user buf[maxUser];
int fullGrade[maxProb];
bool cmp(user &a, user&b) {
	if (a.flag != b.flag) {
		return a.flag > b.flag;
	}
	if (a.total != b.total) {
		return a.total > b.total;
	}
	if (a.perfect != b.perfect) {
		return a.perfect > b.perfect;
	}
	return a.id < b.id;
}
int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &fullGrade[i]);
	}
	for (int i = 0; i <= n; i++) {
		buf[i].id = i;
		buf[i].perfect = 0;
		buf[i].total = 0;
		for (int j = 0; j < maxProb; j++) {
			buf[i].grade[j] = -2;
		}
		buf[i].flag = false;
	}
	int uid, pid, grade;
	int temp_grade;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &uid, &pid, &grade);
		buf[uid].id = uid;
		buf[uid].flag = true;
		temp_grade = grade;
		if (temp_grade > buf[uid].grade[pid]) {
			buf[uid].grade[pid] = temp_grade;
			if (temp_grade == fullGrade[pid]) {
				buf[uid].perfect++;
			}
		}
	}
	for (int i = 1; i <= n;i++) {
		int temp_sum = 0;
		int f = false;
		for (int j = 1; j <= k;j++) {
			if (buf[i].grade[j] >= 0) {
				temp_sum += buf[i].grade[j];
				f = true;
			}
		}
		buf[i].total = temp_sum;
		buf[i].flag = f;
	}
	sort(buf + 1, buf + n + 1, cmp);
	int rank = 1;//计算排名
	for (int i = 1; i <= n; i++) {
		if (buf[i].flag == true) {
			if (i >= 2) {
				if (buf[i - 1].total != buf[i].total) {
					rank = i;
				}
			}
			printf("%d %05d %d ",
				rank,buf[i].id, buf[i].total);
			for (int j = 1; j <= k; j++) {
				if (buf[i].grade[j]==-2) {
					printf("-");
				}
				else if (buf[i].grade[j]==-1) {
					printf("0");
				}else{
					printf("%d",buf[i].grade[j]);
				}
				if (j != k) {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
}
