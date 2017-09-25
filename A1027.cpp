#include<iostream>
using namespace std;
int main() {
	int r, g, b;
	cin >> r >> g >> b;
	int ans[6] = { 0 };
	int index = 0;
	int count = 0;//记录转为13进制后是否有两位数,若没有，则要加0
	do {
		ans[index++] = b % 13;
		b = b / 13;
		count++;
	} while (b != 0);
	if (count == 1) ans[index++] = 0;
	count = 0;
	do {
		ans[index++] = g % 13;
		g = g / 13;
		count++;
	} while (g != 0);
	if (count == 1) ans[index++] = 0;
	count = 0;
	do {
		ans[index++] = r % 13;
		r = r / 13;
		count++;
	} while (r != 0);
	if (count == 1) ans[index++] = 0;
	count = 0;
	cout << "#";
	for (int i = 5; i >= 0; i--) {
		if (ans[i] == 10) {
			cout << "A";
		}
		else if (ans[i] == 11) {
			cout << "B";
		}
		else if (ans[i] == 12) {
			cout << "C";
		}
		else {
			cout << ans[i];
		}
	}
	return 0;
}