#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *buf = new int[n];
	int up = 6, down = -4, stop = 5;
	int total = n*stop;
	int pre = 0;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
		if (i == 0) {
			total += buf[i] * up;
		}
		else {
			int t = buf[i] - buf[i - 1];
			if (t > 0) {
				total += t*up;
			}
			else {
				total += down*t;
			}
		}
	}
	cout << total << endl;
}