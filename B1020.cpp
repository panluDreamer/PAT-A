#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct S {
	double save;
	double total;
	double price;
};
bool cmp(S &a, S &b) {
	return a.price > b.price;
}
int main() {
	int n, d;
	cin >> n >> d;
	int sum = 0;
	double ans;
	int index = 0;
	S *buf = new S[n];
	for (int i = 0; i < n; i++) {
		cin >> buf[i].save;
	}
	for (int i = 0; i < n; i++) {
		cin >> buf[i].total;
		buf[i].price = buf[i].total / buf[i].save;
	}
	sort(buf, buf + n, cmp);
	for (int i = 0; i < n; i++) {
		if (buf[i].save <= d) {
			d -= buf[i].save;
			ans += buf[i].total;
		}
		else {
			ans += buf[i].price*d;
			break;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
	/*for (int i = 0; i < n;i++) {
		if (sum<d) {
			sum += buf[i].save;
			index = i;
		}
	}
	//cout << "index = " << index << endl;
	int count = 0;
	for (int i = 0; i < index;i++) {
		ans += buf[i].total;
		count += buf[i].save;
	}
	//cout << count << endl;
	ans += (d - count)*buf[index].price;
	cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;*/
}