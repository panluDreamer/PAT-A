#include<iostream>
#include<string>
using namespace std;
string deal(string s, int &e, int n);
int main() {
	int n;
	string str1, str2, s1, s2;
	int e1 = 0, e2 = 0;
	cin >> n >> str1 >> str2;
	s1 = deal(str1, e1, n);
	s2 = deal(str2, e2, n);
	if (s1 == s2&&e1 == e2) {
		cout << "YES 0." << s1 << "*10^" << e1 << endl;
	}
	else {
		cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2 << endl;
	}
}
string deal(string s, int &e, int n) {
	int k = 0;
	while (s.length() > 0 && s[0] == '0') {
		s.erase(s.begin());//去前导零
	}
	if (s[0] == '.') {//去完前导零后，第一位为小数点
		s.erase(s.begin());
		while (s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());//去掉小数点后的零，如处理数据000.0002
			e--;
		}
	}
	else {
		while (k < s.length() && s[k] != '.') {//寻找小数点,如处理数据00123.045
			k++;
			e++;
		}
		if (k < s.length()) {//此时为找到小数点时退出的上面循环
			s.erase(s.begin() + k);
		}
	}
	if (s.length() == 0) {//如处理数据0000.000
		e = 0;
	}
	int num = 0;
	k = 0;
	string res;
	while (num < n) {//当精度还没到n
		if (k<s.length()) {
			res += s[k++];
		}
		else {
			res += '0';
		}
		num++;
	}
	return res;
}