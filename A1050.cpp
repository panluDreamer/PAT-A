#include<iostream>
#include<string>
using namespace std;
int map[130] = { 0 };
char temp[10005];
int main() {
	string str1, str2;

	cin.getline(temp, sizeof(temp));
	str1 = temp;
	cin.getline(temp, sizeof(temp));
	str2 = temp;
	//cin >> str1 >> str2;
	int k;
	for (int i = 0; i < str2.length();i++) {
		map[str2.at(i)] = 1;
	}
	for (int i = 0; i < str1.length();i++) {
		if (map[str1.at(i)]==0) {
			cout << str1.at(i);
		}
	}
	return 0;
}