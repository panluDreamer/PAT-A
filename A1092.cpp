#include<iostream>
#include<string>
using namespace std;
int hashTable[150] = { 0 };
int main() {
	string a, b;
	cin >> a >> b;
	int size_a = a.size();
	int size_b = b.size();
	for (int i = 0; i < size_a; i++) {
		hashTable[a.at(i)]++;
	}
	for (int i = 0; i < size_b; i++) {
		hashTable[b.at(i)]--;
	}
	bool flag = false;
	for (int i = 0; i < 150; i++) {
		if (hashTable[i] < 0) {
			flag = true;
			break;
		}
	}
	if (flag == true) {//NO
		cout << "No ";
		int ans = 0;
		for (int i = 0; i < 150; i++) {
			if (hashTable[i] < 0) {
				ans += hashTable[i];
			}
		}
		cout << -ans << endl;
	}
	else {//YES
		cout << "Yes ";
		int ans = 0;
		for (int i = 0; i < 150; i++) {
			ans += hashTable[i];
		}
		cout << ans << endl;
	}
}