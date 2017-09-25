#include<iostream>
#include<string>
using namespace std;
int hash1[125] = { 0 };
int hash2[125] = { 0 };
string a, b;
int k;
bool check(char c, int len) {
	bool flag = true;
	int i = 0;
	while (i < len) {
		if (a[i] == c) {
			if (i + k <= len) {
				for (int j = i; j < i + k; j++) {
					if (a[j] != c) {
						flag = false;
						break;
					}
				}
				i = i + k;
			}
			else {
				flag = false;
				break;
			}
		}
		else {
			i++;
		}
	}
	return flag;
}
int main() {
	cin >> k;
	cin >> a;
	int len = a.length();
	for (int i = 0; i < len; i++) {
		hash1[a[i]]++;
	}
	for (int i = 0; i < 125; i++) {
		if (hash1[i] != 0 && hash1[i] % k == 0) {
			b += (char)i;
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (check(b[i], len)) {
			cout << b[i];
			hash2[b[i]] = 1;
		}
	}
	cout << endl;
	int i = 0;
	while (i < len) {
		if (hash2[a[i]] == 0) {
			cout << a[i];
			i++;
		}
		else {
			cout << a[i];
			i += k;
		}
	}
	return 0;
}