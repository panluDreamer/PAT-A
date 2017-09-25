#include<iostream>
#include<string>
using namespace std;
string check(string a, string b);
int main() {
	int n;
	cin >> n;
	getchar();//注意要添加接收换行符的这一行代码
	string *buf = new string[n];
	char t[260];
	for (int i = 0; i < n; i++) {
		//cin.getline(t,260);
		cin.getline(t, sizeof(t));
		buf[i] = t;
		//cout << i << endl;
	}
	string curr_max;
	curr_max = check(buf[0], buf[1]);
	//cout << check(buf[0], buf[1]);
	if (n >= 3) {
		for (int i = 2; i < n; i++) {
			curr_max = check(curr_max, buf[i]);
			if (curr_max.length()==0) {
				break;
			}
		}
	}
	if (curr_max.length() != 0) {
		cout << curr_max;
	}
	else {
		cout << "nai";
	}
}
string check(string a, string b) {
	string temp;
	int la = a.length();
	int lb = b.length();
	int ia = la - 1, ib = lb - 1;
	while (ia >= 0 && ib >= 0) {
		if (a[ia] == b[ib]) {
			ia--;
			ib--;
		}
		else {
			break;
		}
	}
	temp = a.substr(ia + 1, la);
	return temp;
}