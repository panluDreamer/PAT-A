/**
*±©Á¦½â·¨
*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string intToString(int num) {
	stringstream ss;
	ss << num;
	string s = ss.str();
	return s;
}
int getNum(string s) {
	int ans = 0;
	int t = s.length();
	for (int i = 0; i < t;i++) {
		if (s[i]=='1') {
			ans++;
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	string temp;
	int sum = 0;
	for (int i = 1; i <= n;i++) {
		temp = intToString(i);
		sum+= getNum(temp);
	}
	cout << sum << endl;
}