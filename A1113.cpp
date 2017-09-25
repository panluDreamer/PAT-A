#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 100010;
int buf[maxn] = { 0 };
int mid;
bool cmp(int a,int b) {
	return a < b;
}
int main() {
	int n;
	int n1 = 0, n2 = 0, s1 = 0, s2 = 0;
	int gap = -1;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> buf[i];
	}
	sort(buf, buf + n, cmp);
	if (n % 2 == 0) {
		n1 = n / 2;
		n2 = n / 2;
		gap = 0;
		for (int i = 0; i < n1;i++) {
			s1 += buf[i];
		}
		for (int i = n1; i < n;i++) {
			s2 += buf[i];
		}
	}
	else {
		//int temp1 = n / 2;
		gap = 1;
		n1 = n / 2;
		for (int i = 0; i < n1;i++) {
			s1 += buf[i];
		}
		for (int i = n1; i < n;i++) {
			s2 += buf[i];
		}
	}

	cout << gap<< " " << abs(s1 - s2);
	return 0;

}