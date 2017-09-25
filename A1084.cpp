#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn = 120;
int hashTable[maxn] = { 0 };
int main() {
	string a, b;
	cin >> a >> b;
	int b_size = b.size();
	int a_size = a.size();
	for (int i = 0; i < b_size; i++) {
		hashTable[b.at(i)]++;
	}
	vector<char> ans;
	for (int i = 0; i < a_size; i++) {
		char ch = a.at(i);
		if (ch == '_') {
			if (hashTable[ch] == 0) {
				ans.push_back(ch);
				hashTable[ch] = 1;
			}
		}
		else if (ch >= '0'&&ch <= '9') {
			if (hashTable[ch] == 0) {
				ans.push_back(ch);
				hashTable[ch] = 1;
			}
		}
		else if (ch >= 'a'&&ch <= 'z') {
			if (hashTable[ch] == 0 && hashTable[ch - 32] == 0) {
				ans.push_back(ch);
				hashTable[ch] = 1;
			}
		}
		else {
			if (hashTable[ch] == 0 && hashTable[ch + 32] == 0) {
				ans.push_back(ch);
				hashTable[ch] = 1;
			}
		}
	}
	int size = ans.size();
	for (int i = 0; i < size; i++) {
		if (ans.at(i) >= 'a'&&ans.at(i) <= 'z') {
			cout << (char)(ans.at(i) - 32);
		}
		else {
			cout << ans.at(i);
		}
	}
	cout << endl;
}