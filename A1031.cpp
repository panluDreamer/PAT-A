#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n1, n2, n3;
	int len = s.length();
	for (n2 = 3; n2 <= len; n2++) {
		if ((len + 2 - n2) % 2 == 0) {
			if ((len + 2 - n2) / 2 <= n2) {
				n1 = n3 = (len + 2 - n2) / 2;
				break;
			}
		}
	}
	//cout << n1 << " " << n2 << " " << n3 << endl;
	for (int i = 0; i < n1 - 1; i++) {
		cout << s[i];
		for (int j = 0; j < n2 - 2; j++) {
			cout << " ";
		}
		cout << s[len - 1 - i];
		cout << endl;
	}
	for (int k = n1 - 1; k <= n1 + n2 - 2; k++) {
		cout << s[k];
	}
	return 0;
}