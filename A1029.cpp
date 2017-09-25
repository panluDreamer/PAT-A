#include<iostream>
using namespace std;
const int maxn = 1000010;
long int a[maxn] = { 0 };
long int b[maxn] = { 0 };
int m, n;
int main() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int ans = -1;
	int i = 0, j = 0;
	int count = 0, aim;
	if ((m + n) % 2 == 0) {
		aim = (m + n) / 2;
	}
	else {
		aim = (m + n) / 2 + 1;
	}
	while (i < m&&j < n) {
		if (a[i] < b[j]) {
			count++;
			if (count == aim) {
				ans = a[i];
				break;
			}
			i++;
		}
		else {
			count++;
			if (count == aim) {
				ans = b[j];
				break;
			}
			j++;
		}
	}
	if (count < aim) {
		while (i < m) {
			count++;
			if (count == aim) {
				ans = a[i];
				break;
			}
			i++;
		}
	}
	if (count < aim) {
		while (j < n) {
			count++;
			if (count == aim) {
				ans = b[j];
				break;
			}
			j++;
		}
	}
	cout << ans << endl;
}