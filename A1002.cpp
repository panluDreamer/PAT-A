#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
const int maxn = 1010;
const int inf = 0x3fffffff;
double buf[maxn];
int main() {
	fill(buf, buf + maxn, inf);
	int k;
	int exp;
	double co;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> exp >> co;
		if (buf[exp] == inf) {
			buf[exp] = co;
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> exp >> co;
		if (buf[exp] == inf) {
			buf[exp] = co;
		}
		else {
			buf[exp] += co;
		}
	}
	int count = 0;
	for (int i = 1005; i >= 0; i--) {
		if (buf[i] != inf&&buf[i] != 0) {//还须判断系数不为0
			count++;
		}
	}
	cout << count;
	for (int i = 1005; i >= 0; i--) {
		if (buf[i] != inf&&buf[i] != 0) {
			cout << " " << i << " ";
			cout << setiosflags(ios::fixed) << setprecision(1) << buf[i];
		}
	}
	cout << endl;
}