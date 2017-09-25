#include<iostream>
#include<string>
using namespace std;
struct user {
	string name;
	string pass;
	bool flag;
};
user buf[1005];
int main() {
	int n;
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf[i].name >> buf[i].pass;
		buf[i].flag = false;
		int len = buf[i].pass.length();
		for (int j = 0; j < len; j++) {
			if (buf[i].pass[j] == '1') {
				buf[i].pass[j] = '@';
				buf[i].flag = true;
			}
			else if (buf[i].pass[j] == '0') {
				buf[i].pass[j] = '%';
				buf[i].flag = true;
			}
			else if (buf[i].pass[j] == 'l') {
				buf[i].pass[j] = 'L';
				buf[i].flag = true;
			}
			else if (buf[i].pass[j] == 'O') {
				buf[i].pass[j] = 'o';
				buf[i].flag = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (buf[i].flag) {
			count++;
		}
	}
	if (count != 0) {
		cout << count << endl;
		for (int i = 0; i < n; i++) {
			if (buf[i].flag) {
				cout << buf[i].name << " " << buf[i].pass << endl;
			}
		}
	}
	else {
		if (n == 1) {
			cout << "There is " << n << " account and no account is modified";
		}
		else {
			cout << "There are " << n << " accounts and no account is modified";
		}

	}
	return 0;
}