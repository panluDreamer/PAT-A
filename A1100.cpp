#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string map1[13] = { "","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string map2[13] = { "","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
int main() {
	int n;
	cin >> n;
	getchar();//\n
	char s[260];
	string a;
	for (int i = 0; i < n; i++) {
		cin.getline(s, sizeof(s));
		a = s;
		//cout << "a=" << a << endl;
		if (a.at(0) >= '0'&&a.at(0) <= '9') {//Earth
			int num;
			stringstream ss;
			ss << a;
			ss >> num;
			//cout << "num = " << num << endl;
			int d1, d2;
			d1 = num / 13;
			d2 = num % 13;
			if (d2 != 0 && d1 != 0) {
				cout << map2[d1] << " " << map1[d2] << endl;
			}
			else if (d1 == 0 && d2 != 0) {
				cout << map1[d2] << endl;
			}
			else if (d1 != 0 && d2 == 0) {
				cout << map2[d1] << endl;
			}
			else {
				cout << "tret" << endl;
			}
		}
		else {//Mars  tret 0
			int size = a.length();
			int ans;
			if (a == "tret" || a == "tret tret") {
				cout << "0" << endl;
			}
			else {
				if (size == 3) {
					ans = -1;
					for (int i = 0; i < 13; i++) {
						if (map2[i] == a) {
							ans = i;
							break;
						}
					}
					if (ans == -1) {
						for (int i = 0; i < 13; i++) {
							if (map1[i] == a) {
								ans = i;
								break;
							}
						}
						cout << ans << endl;
					}
					else {
						cout << ans * 13 << endl;
					}
				}
				else if (size == 7) {
					string a1, a2;
					a1 = a.substr(0, 3);
					a2 = a.substr(4, 3);
					int d1, d2;
					for (int i = 0; i < 13; i++) {
						if (map2[i] == a1) {
							d1 = i;
							break;
						}
					}
					for (int i = 0; i < 13; i++) {
						if (map1[i] == a2) {
							d2 = i;
							break;
						}
					}
					cout << d1 * 13 + d2 << endl;
				}
			}
		}
	}
}