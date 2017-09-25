#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int d[111];
bool isPrime(int n) {
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <=sqr; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int num, r, con;
	bool flag1 = true, flag2 = true;
	while (cin >> num) {
		if (num < 0) break;
		cin >> r;
		if (isPrime(num)==false) {
			cout << "No" << endl;
		}
		else {
			int len = 0;
			do {
				d[len++] = num%r;
				num /= r;
			} while (num != 0);
			//int p = 1;
			int another_num = 0;
			for (int i = 0; i < len;i++) {
				//num = num*r + d[i];//转十进制？
			//	num = num + d[i] * p;
			//	p = p*r;
				another_num = another_num*r + d[i];
			}
			if (isPrime(another_num)==false) {
				cout << "No" << endl;
			}
			else {
				cout << "Yes" << endl;
			}
		}
	}
	return 0;

}