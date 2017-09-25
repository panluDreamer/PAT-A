/*
*一个程序中最好使用cout或者printf,不要两者混用
*加强理解贪心策略！
*To Fill or not not Fill
*/
#include<algorithm>
#include<stdio.h>
using namespace std;
struct station {
	double price;
	double dis;
}st[550];
bool cmp(station a, station b) {
	return a.dis < b.dis;
}
int main() {
	double c, d, davg;
	int n;
	//cin >> c >> d >> davg >> n;
	scanf("%lf%lf%lf%d", &c, &d, &davg, &n);
	for (int i = 0; i < n; i++) {
		//	cin >> st[i].price >> st[i].dis;
		scanf("%lf%lf", &st[i].price, &st[i].dis);
	}
	st[n].price = 0;
	st[n].dis = d;
	sort(st, st + n, cmp);
	if (st[0].dis != 0) {
		//cout << "The maximum travel distance = 0.00";
		printf("The maximum travel distance = 0.00\n");
	}
	else {
		int now;
		double now_tank = 0, total_price;
		now = 0;
		while (now < n) {
			int k = -1;//最低油价的加油站编号
			double min_price = 1000000;
			for (int i = now + 1; i <= n&&st[i].dis - st[now].dis <= c*davg; i++) {
				if (st[i].price < min_price) {
					min_price = st[i].price;
					k = i;
					if (min_price < st[now].price) {
						break;
					}
				}
			}
			if (k == -1) break;
			double need = (st[k].dis - st[now].dis) / davg;
			if (min_price < st[now].price) {
				if (now_tank < need) {
					total_price += (need - now_tank)*st[now].price;
					now_tank = 0;//到达k后邮箱为0
				}
				else {
					now_tank -= need;
				}
			}
			else {
				total_price += (c - now_tank)*st[now].price;
				now_tank = c - need;
			}
			now = k;
		}
		//cout << total_price << endl;
		if (now == n) {
			printf("%.2f\n", total_price);
		}
		else {
			printf("The maximum travel distance = %.2f\n", st[now].dis + c*davg);
		}
	}
	return 0;
}