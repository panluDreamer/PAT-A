//Radix
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
using namespace std;
int find_max_digit(string s);
int main() {
	//ifstream cin("C:\\Users\\Administrator\\Desktop\\input.txt");
	string a, b;
	int tag;
	int radix = 0;
	cin >> a >> b;
	cin >> tag;
	cin >> radix;
	int len_a = a.length();
	int len_b = b.length();

	//calculate
	if (tag == 1) {
		int r_a = 0;
		int a_index = 0;
		for (int i = len_a - 1; i >= 0; i--) {
			if (a.at(a_index) >= 48 && a.at(a_index) <= 57) {
				r_a += (a.at(a_index) - 48)*pow((double)radix, i);
			}
			else if (a.at(a_index) >= 97 && a.at(a_index) <= 122) {
				r_a += (a.at(a_index) - 87)*pow((double)radix, i);
			}
			a_index++;
		}

		//cout<<"r_a = "<<r_a<<endl;
		int max_b_digit = find_max_digit(b);
		//cout<<"max_b_digit = "<<max_b_digit<<endl;
		int record = 0;
		for (int i = max_b_digit; i <= 1000; i++) {
			record = i;
			int b_index = 0;
			int r_b = 0;
			for (int m = len_b - 1; m >= 0; m--) {
				if (b.at(b_index) >= 48 && b.at(b_index) <= 57) {
					r_b += (b.at(b_index) - 48)*pow((double)i, m);
				}
				else if (b.at(b_index) >= 97 && b.at(b_index) <= 122) {
					r_b += (b.at(b_index) - 87)*pow((double)i, m);
				}
				b_index++;
			}
			if (r_b == r_a) {
				cout << i << endl; break;
			}
			if (r_b>r_a) {
				cout << "Impossible" << endl; break;
			}
		}
		if (record >= 1000) {
			cout << "Impossible" << endl;
		}

	}
	else if (tag == 2) {
		int r_b = 0;
		int b_index = 0;
		for (int i = len_b - 1; i >= 0; i--) {
			if (b.at(b_index) >= 48 && b.at(b_index) <= 57) {
				r_b += (b.at(b_index) - 48)*pow((double)radix, i);
			}
			else if (b.at(b_index) >= 97 && b.at(b_index) <= 122) {
				r_b += (b.at(b_index) - 87)*pow((double)radix, i);
			}
			b_index++;
		}
		//cout<<"r_b = "<<r_b<<endl;
		int max_a_digit = find_max_digit(a);
		int record = 0;
		for (int i = max_a_digit; i <= 1000; i++) {
			record = i;
			int  r_a = 0;
			int a_index = 0;
			for (int m = len_a - 1; m >= 0; m--) {
				//  cout<<"m="<<m<<endl;
				if (a.at(a_index) >= 48 && a.at(a_index) <= 57) {
					r_a += (a.at(a_index) - 48)*pow((double)i, m);
				}
				else if (a.at(a_index) >= 97 && a.at(a_index) <= 122) {
					r_a += (a.at(a_index) - 87)*pow((double)i, m);
				}
				a_index++;
			}
			//cout<<i<<": r_a-->"<<r_a<<endl;
			if (r_a == r_b) {
				cout << i << endl; break;
			}
			if (r_a > r_b) {
				cout << "Impossible" << endl; break;
			}
		}
		//cout<<"out"<<endl;
		//cout<<"record = "<<record<<endl;
		if (record >= 1000) {
			cout << "Impossible" << endl;
		}
	}
}
int find_max_digit(string s) {
	int len = s.length();
	int max = -1;
	for (int i = 0; i<len; i++) {
		if (s.at(i) >= 48 && s.at(i) <= 57) {
			if ((s.at(i) - 48)>max) {
				max = s.at(i) - 48;
			}
		}
		if (s.at(i) >= 97 && s.at(i) <= 122) {
			if ((s.at(i) - 87)>max) {
				max = s.at(i) - 87;
			}
		}
	}
	return max;
}