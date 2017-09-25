/**
*Cars on Campus
*筛选有效记录，map映射每辆车的停车时间，利用查询时间逐渐增加的数据特点
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
using namespace std;
struct record {
	char number[10];
	int time;
	char status[5];
};
const int maxn = 10010;
int n, k;
int num = 0;//有效记录的条数
int maxTime = -1;
map<string, int> parkTime;
record buf[maxn], valid[maxn];
bool cmp(record &a, record &b) {
	if (strcmp(a.number, b.number)) {
		return strcmp(a.number, b.number) < 0;
	}
	else {
		return a.time < b.time;
	}
}
bool cmp2(record &a, record &b) {
	return a.time < b.time;
}
void selectValidRecord() {
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(buf[i].number, buf[i + 1].number) == 0
			&& strcmp(buf[i].status, "in") == 0
			&& strcmp(buf[i + 1].status, "out") == 0) {
			valid[num++] = buf[i];
			valid[num++] = buf[i + 1];
			int inTime = buf[i + 1].time - buf[i].time;
			if (parkTime.count(buf[i].number) == 0) {
				parkTime[buf[i].number] = 0;
			}
			parkTime[buf[i].number] += inTime;
			maxTime = max(maxTime, parkTime[buf[i].number]);
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	char number[10], status[5];
	int h, m, s;
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d %s", &buf[i].number, &h, &m, &s, &buf[i].status);
		buf[i].time = h * 3600 + m * 60 + s;
	}
	sort(buf, buf + n, cmp);
	//printf("init:\n");
//	for (int i = 0; i < n;i++) {
//		printf("%s %d %s\n", buf[i].number, buf[i].time, buf[i].status);
//	}
	selectValidRecord();
	//printf("valid number = %d\n", num);
	sort(valid, valid + num, cmp2);
	//	for (int i = 0; i < num; i++) {
		//	printf("%s %d %s\n", valid[i].number, valid[i].time, valid[i].status);
		//}
		//m次查询
	int time;
	int now = 0;//指向当前记录
	int carNum = 0;
	//printf("k=%d\n",k);
	for (int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &h, &m, &s);
		time = h * 3600 + m * 60 + s;
		while (now < num&&valid[now].time <= time) {//因为按照时间递增顺序查询
			if (strcmp(valid[now].status, "in") == 0) {
				carNum++;
			}
			else {
				carNum--;
			}
			now++;
		}
		printf("%d\n", carNum);
	}
	map<string, int>::iterator it;
	for (it = parkTime.begin(); it != parkTime.end(); it++) {
		if (it->second == maxTime) {
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 3600 % 60);

}