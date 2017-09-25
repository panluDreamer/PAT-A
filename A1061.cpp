#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
string day[8] = { "","MON","TUE","WED","THU","FRI","SAT","SUN" };
map<char, int> mp;
vector<int> index;
void init() {
	mp['0'] = 0;
	mp['1'] = 1;
	mp['2'] = 2;
	mp['3'] = 3;
	mp['4'] = 4;
	mp['5'] = 5;
	mp['6'] = 6;
	mp['7'] = 7;
	mp['8'] = 8;
	mp['9'] = 9;
	mp['A'] = 10;
	mp['B'] = 11;
	mp['C'] = 12;
	mp['D'] = 13;
	mp['E'] = 14;
	mp['F'] = 15;
	mp['G'] = 16;
	mp['H'] = 17;
	mp['I'] = 18;
	mp['J'] = 19;
	mp['K'] = 20;
	mp['L'] = 21;
	mp['M'] = 22;
	mp['N'] = 23;
}
int main() {
	init();
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int len_a = a.size();
	int len_b = b.size();
	int len_c = c.size();
	int len_d = d.size();
	int count = 0;
	int i = 0, j = 0;
	char day_char, h;
	while (i < len_a&&j < len_b) {
		if (count == 1) {
			if ((a.at(i) >= '0'&&a.at(i) <= '9' || a.at(i) >= 'A'&&a.at(i) <= 'N') &&
				(b.at(j) >= '0'&&b.at(j) <= '9' || b.at(j) >= 'A'&&b.at(j) <= 'N')) {//限制为0~9,A~N
				if (a.at(i) == b.at(j)) {
					h = a.at(i);
					break;
				}
			}
		}
		if (a.at(i) >= 'A'&&a.at(i) <= 'G'&&b.at(j) >= 'A'&&b.at(j) <= 'G'&&count == 0) {//A~G,存在不再这个范围的相同的大写字符
			if (a.at(i) == b.at(j)) {
				count++;
				//index.push_back(i);
				day_char = a.at(i);
			}
		}

		i++;
		j++;
	}
	//cout << index.size() << endl;
	//cout << a.at(index.at(0)) << "  " << a.at(index.at(1)) << endl;
	//cout << "h = " << (char)h << endl;
	int hour = mp[h];
	cout << day[day_char - 'A' + 1] << " ";
	printf("%02d:", hour);
	i = 0, j = 0;
	int m_index = -1;
	while (i < len_c&&j < len_d) {
		if (((c.at(i) >= 'A'&&c.at(i) <= 'Z') ||
			(c.at(i) >= 'a'&&c.at(i) <= 'z')) && (
			(d.at(i) >= 'A'&&d.at(i) <= 'Z') ||
				(d.at(i) >= 'a'&&d.at(i) <= 'z'))) {
			if (c.at(i) == d.at(j)) {
				m_index = i;
				break;
			}
		}
		i++;
		j++;
	}
	printf("%02d\n", m_index);
}