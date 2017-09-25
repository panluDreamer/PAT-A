#include<iostream>
using namespace std;
void print(int a[], int size);
int main() {
	int buf[10];
	for (int i = 0; i < 10; i++) {
		cin >> buf[i];
	}
	bool flag = false;
	int index = -1;
	if (buf[0] != 0) {
		flag = true;
		for (int i = 1; i < 10; i++) {
			if (buf[i] != 0) {
				index = i;
				break;
			}
		}
	}
	if (flag) {
		cout << index;
		buf[index]--;
		print(buf, 10);
		return 0;
	}
	else {
		print(buf, 10);
		return 0;
	}
}
void print(int a[], int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] != 0) {
			for (int j = 0; j < a[i]; j++) {
				cout << i;
			}
		}
	}
}