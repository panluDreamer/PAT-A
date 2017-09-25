#include<iostream>
using namespace std;
int buf[10005] = { 0 };
int main() {
	int n;
	cin >> n;
	int temp;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[i] = temp;
		buf[temp]++;
	}
	int i;
	for (i = 0; i < n; i++) {
		if (buf[a[i]] == 1) {
			cout << a[i];
			break;
		}
	}
	if (i == n) {
		cout << "None";
	}
}