#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

int main() {
	string a;
	cin >> a;
	int len = a.length();
	char sign = a.at(0);
	int E_pos = a.find("E");
	string sub = a.substr(3, E_pos - 3);
	//cout << "sub = " << sub << endl;
	string e = a.substr(E_pos + 1, len);
	int exp = stringToNum<int>(e);
	//cout << "exp = " << exp << endl;
	if (sign=='-') {
		cout << "-";
	}
	if (exp > 0) {
		cout << a.at(1);
		int sub_len = sub.length();
		if (sub_len > exp) {
			int index = 0;
			while (index < exp) {
				cout << sub[index++];
			}
			cout << ".";
			while (index < sub_len) {
				cout << sub[index++];
			}
		}
		else if (sub_len == exp) {
			int sub_len = sub.length();
			int index = 0;
			while (index < sub_len) {
				cout << sub[index++];
			}
		}
		else {
			int sub_len = sub.length();
			int index = 0;
			while (index < sub_len) {
				cout << sub[index++];
			}
			int zero_count = exp - sub_len;
			while (zero_count--) {
				cout << "0";
			}
		}
	}
	else if (exp == 0) {
		cout << a.at(1);
		int sub_len = sub.length();
		int index = 0;
		while (index < sub_len) {
			cout << sub[index++];
		}
	}
	else {
		cout << "0.";
		int zero_count = abs(exp) - 1;
		while (zero_count--) {
			cout << "0";
		}
		cout << a.at(1);
		int sub_len = sub.length();
		int index = 0;
		while (index < sub_len) {
			cout << sub[index++];
		}
	}
}