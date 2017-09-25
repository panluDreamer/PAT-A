//如果使用long long 类型存放数字，会溢出，使用string类型存放，再在字符串上模拟计算*2操作
#include<iostream>
#include<string>
using namespace std;
const int maxn = 12;
int ha[maxn] = { 0 };
int main() {
	string a, b;
	bool flag = true;
	cin >> a;
	b = a;
	int len = a.length();
	for (int i = 0; i < len;i++) {
		ha[a[i] - '0']++;
	}
	int carry = 0;
	for (int i = len - 1; i >= 0;i--) {
		b[i] = ((a[i] - '0') * 2 + carry) % 10 + '0';
		carry = ((a[i] - '0') * 2 + carry) / 10;
	}
	if (carry != 0) {
		char c = carry + '0';
		b = c + b;
		cout << "No" << endl;
		cout << b;
	}
	else {
		for (int i = 0; i < b.length();i++) {
			if (ha[b[i] - '0'] > 0) {
				ha[b[i] - '0']--;
			}
			else {
				flag = false;
				break;
			}
		}
		for (int i = 0; i < 10; i++) {
			if (ha[i] != 0) {
				flag = false;
				break;
			}
		}
		if (flag == false) {
			cout << "No" << endl;
			cout << b;
		}
		else {
			cout << "Yes" << endl;
			cout << b;
		}
	}
}
