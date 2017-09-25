/**
*Phone Bills 
*要好好理解思想，处理起来比较麻烦
*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct Bill {
	char name[25];
	int month;
	int day;
	int hour;
	int minute;
	char stat[15];
};
void cal_money(int s_d, int s_h, int s_m, int e_d, int e_h, int e_m, int &time, int &money);
bool cmp(Bill a, Bill b) {
	int s = strcmp(a.name, b.name);
	if (s != 0) {
		return s < 0;//姓名顺序优先
	}
	//if (strcmp(a.name, b.name) < 0) {
	//	return true;    //不能这样写
	//}
	else if (a.month != b.month) {
		return a.month < b.month;
	}
	else if (a.day != b.day) {
		return a.day < b.day;
	}
	else if (a.hour != b.hour) {
		return a.hour < b.hour;
	}
	else {
		return a.minute < b.minute;
	}

}
int price[24] = { 0 };
int main() {
	int p;
	for (int i = 0; i < 24; i++) {
		//	cin >> p;
		scanf("%d", &p);
		price[i] = p;
	}
	int num;
	//cin >> num;
	scanf("%d", &num);
	Bill *buf = new Bill[num];
	Bill temp;
	vector<Bill> v;
	for (int i = 0; i < num; i++) {
		scanf("%s %d:%d:%d:%d %s", &temp.name, &temp.month,
			&temp.day, &temp.hour, &temp.minute, &temp.stat);
		buf[i] = temp;
	}
	sort(buf, buf + num, cmp);
	//	printf("-------------------\n");
		//for (int i = 0; i < num; i++) {
		//	printf("%s %02d:%02d:%02d:%02d %s\n",
		//		buf[i].name, buf[i].month, buf[i].day, buf[i].hour, buf[i].minute, buf[i].stat);
		//}
		//bool flag = false;

	int on = 0, off, next;
	while (on < num) {
		int needPrint = 0;
		next = on;
		while (next < num&&strcmp(buf[next].name, buf[on].name) == 0) {
			if (needPrint == 0 && strcmp(buf[next].stat, "on-line") == 0) {
				needPrint = 1;
			}
			else if (needPrint == 1 && strcmp(buf[next].stat, "off-line") == 0) {
				needPrint = 2;
			}
			next++;
		}
		if (needPrint < 2) {//没有找到配对的on-line与off-line
			on = next;
			continue;//继续寻找下一个用户
		}
		int all_money = 0;
		printf("%s %02d\n", buf[on].name, buf[on].month);
		while (on < next) {//寻找该用户的所有配对
			while (on < next - 1 && !(strcmp(buf[on].stat, "on-line") == 0 
				&& strcmp(buf[on + 1].stat, "off-line") == 0)) {
				on++;//寻找连续的on-line和off-line
			}
			off = on + 1;
			if (off == next) {//已经输出完该用户配对的所有记录
				on = next;//设置下一用户的寻找起点
				break;
			}
			printf("%02d:%02d:%02d ", buf[on].day, buf[on].hour, buf[on].minute);
			printf("%02d:%02d:%02d ", buf[off].day, buf[off].hour, buf[off].minute);
			int time = 0, money = 0;
			cal_money(buf[on].day, buf[on].hour, buf[on].minute,
				buf[off].day, buf[off].hour, buf[off].minute, time, money);
			all_money += money;//总金额
			printf("%d $%.2f\n", time, money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", all_money / 100.0);
	}
	//for (int i = 0; i+1 < num;i++) {
	//	if ((strcmp(buf[i].name, buf[i + 1].name) == 0)
	//		&& (strcmp(buf[i].stat, "on-line") == 0)
	//		&& (strcmp(buf[i + 1].stat, "off-line") == 0)) {
		//	printf("%s %02d\n", buf[i].name, buf[i].month);
		//	printf("%02d:%02d:%02d %02d:%02d:%02d\n",
		//		buf[i].day, buf[i].hour, buf[i].minute,
		//		buf[i + 1].day, buf[i + 1].hour, buf[i + 1].minute);
	//	}
//	}
	return 0;
}
//计算每次通话的金额，注意统计两次时间的间隔的方法
void cal_money(int s_d, int s_h, int s_m, int e_d, int e_h, int e_m, int &time, int &money) {
	//int temp_hour = s_h;
	while (s_d < e_d || s_h < e_h || s_m < e_m) {
		time++;
		money += price[s_h];
		s_m++;
		if (s_m >= 60) {
			s_m = 0;
			s_h++;//进入下一小时
		}
		if (s_h >= 24) {
			s_h = 0;
			s_d++;//进入下一天
		}
	}
}