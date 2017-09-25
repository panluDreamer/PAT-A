#include<iostream>
#include<iomanip>
using namespace std;
double buf[100010] = { 0.0 };
int main() {
	int n;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> buf[i];
	}
	double now = 0.0;
	for (int i = 0; i < n;i++) {//time out
		now = buf[i];
		sum += now;
		for (int j = i + 1; j < n;j++) {
			now += buf[j];
			sum += now;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
}