#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct mooncake {
	double amount;
	double profit;
	double price;
};
mooncake buf[1010];
bool cmp(mooncake &a, mooncake &b) {
	return a.price > b.price;
}
int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n;i++) {
		cin >> buf[i].amount;
	}
	for (int i = 0; i < n;i++) {
		cin >> buf[i].profit;
		buf[i].price = buf[i].profit / buf[i].amount;
	}
	sort(buf, buf + n, cmp);
	int cur = 0;
	double total = 0;
	for (int i = 0; i < n;i++) {
		if (buf[i].amount <= d) {
			total += buf[i].profit;
			d -= buf[i].amount;
		}
		else {
			total += d*buf[i].price;
			d = 0;
			break;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << total << endl;
}