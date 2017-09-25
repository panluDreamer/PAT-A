#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
struct type {
	string value;
	bool flag;
};
const int maxn = 110;
type buf[maxn];
int n;
double sum = 0.0;
template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

void show(type a[]) {
	for (int i = 0; i < n; i++) {
		if (a[i].flag == true) {
			cout << a[i].value << " ";
		}
	}
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf[i].value;
		buf[i].flag = true;
	}
	for (int i = 0; i < n; i++) {//去除含有非法字符的value
		string temp = buf[i].value;
		int s = temp.size();
		for (int j = 0; j < s; j++) {
			if (!((temp.at(j) >= '0'&&temp.at(j) <= '9') || temp.at(j) == '.' || temp.at(j) == '-')) {
				buf[i].flag = false;
				break;
			}
		}
	}
	//show(buf);
	for (int i = 0; i < n; i++) {//检查两位小数，和大小范围
		if (buf[i].flag == true) {
			string temp = buf[i].value;
			int s = temp.size();
			int ans = -1;
			for (int j = 0; j < s; j++) {
				if (temp.at(j) == '.') {
					ans = j;
					break;
				}
			}
			if (ans == -1) {//int
				int t = stringToNum<int>(buf[i].value);
				if (t >= -1000 && t <= 1000) {
					buf[i].flag = true;
					sum += t;
				}
				else {
					buf[i].flag = false;
				}
			}
			else {//have .
				string sub = temp.substr(ans + 1, s);
				if (sub.size() > 2) {
					buf[i].flag = false;
				}
				else {
					float f = stringToNum<float>(buf[i].value);
					if (f >= -1000 && f <= 1000) {
						buf[i].flag = true;
						sum += f;
					}
					else {
						buf[i].flag = false;
					}
				}
			}
		}
	}
//	cout << endl;
//	cout << "after: ";
//	show(buf);
//	cout << "sum = " << sum << endl;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (buf[i].flag == false) {
			cout << "ERROR: " << buf[i].value << " is not a legal number" << endl;;
		}
		else {
			count++;
		}
	}
	if (count != 0) {
		if (count == 1) {
			cout << "The average of " << count << " number is ";
		}else{
			cout << "The average of " << count << " numbers is ";
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << sum / count << endl;
	}
	else {
		cout << "The average of 0 numbers is Undefined" << endl;
	}
}