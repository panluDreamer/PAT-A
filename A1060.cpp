#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void test(string a, int int_alen, int n, bool flag, int len_a, string &con_a);
int main() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	int len_a = a.length();
	int len_b = b.length();
	int int_alen = 0, int_blen = 0;
	bool a_f = false, b_f = false;
	for (int i = 0; i < len_a; i++) {
		if (a.at(i) == '.') {
			int_alen = i;
			a_f = true;
			break;
		}
	}
	if (int_alen == 0) {
		int_alen = len_a;
	}
	for (int i = 0; i < len_b; i++) {
		if (b.at(i) == '.') {
			int_blen = i;
			b_f = true;
			break;
		}
	}
	if (int_blen == 0) {
		int_blen = len_b;
	}
	string con_a, con_b;
	test(a, int_alen, n, a_f, len_a, con_a);
	test(b, int_blen, n, b_f, len_b, con_b);
	bool flag = false;
	//for (int i = 0; i < n&&i < int_alen&&i < int_blen; i++) {
	//	if (a.at(i)!=b.at(i)) {
	////		flag = true;
	//	}
	//}
	for (int i = 0; i < n; i++) {
		if (con_a.at(i) != con_b.at(i)) {
			flag = true;
		}
	}
	
	if (flag||int_alen!=int_blen) {
		cout << "NO ";
		cout << "0." << con_a << "*10^" << int_alen;
		cout << " ";
		cout << "0." << con_b << "*10^" << int_blen;
	}
	else {
		cout << "YES ";
		bool f = false;
		for (int i = 0; i < n;i++) {
			if (con_a.at(i)!='0') {
				f = true;
			}
		}
		if (f) {
			cout << "0." << con_a << "*10^" << int_alen;
		}
		else {
			cout << "0." << con_a << "*10^0";
		}
		
	}
}
void test(string a, int int_alen, int n, bool flag, int len_a, string &con_a) {
	if (int_alen >= n) {
		//cout << "0.";
		for (int i = 0; i < n; i++) {
			//cout << a.at(i);
			con_a += a.at(i);
		}
		//cout << "*10^" << int_alen;
	}
	else if (int_alen < n) {
		//cout << "0.";
		for (int i = 0; i < int_alen; i++) {
			//cout << a.at(i);
			con_a += a.at(i);
		}
		if (flag) {//有小数点
			if (n <= len_a - 1) {
				for (int i = int_alen + 1; i <= n; i++) {
					//cout << a.at(i);
					con_a += a.at(i);
				}
				//cout << "*10^" << int_alen;
			}
			else {
				for (int i = int_alen + 1; i < len_a; i++) {
					//cout << a.at(i);
					con_a += a.at(i);
				}
				for (int i = len_a; i <= n; i++) {
					//	cout << "0";
					con_a += '0';
				}
				//	cout << "*10^" << int_alen;
			}
		}
		else {//没有小数点
			for (int i = int_alen; i < n; i++) {
				//cout << "0";
				con_a += '0';
			}
			//cout << "*10^" << int_alen;
		}
	}
}