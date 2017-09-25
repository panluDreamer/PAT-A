#include<iostream>
using namespace std;
int ans[10000] = { 0 };
int main() {
	int num, b, index = 0;
	bool flag = true;
	cin >> num >> b;
	do {
		ans[index++] = num%b;
		num = num / b;
	} while (num != 0);
	//cout << index << endl;
	for (int i = 0; i < index / 2; i++) {
		if (ans[i] != ans[index - 1 - i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	for (int i = index - 1; i > 0; i--) {
		cout << ans[i] << " ";
	}
	cout << ans[0];
	return 0;
}