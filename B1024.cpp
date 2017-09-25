#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;
int main() {
	string a;
	cin >> a;
	int size = a.length();
	char sign = a.at(0);
	char c1 = a.at(1);
	int id = -1;
	for (int i = 3; i < size; i++) {
		if (a.at(i) == 'E') {
			id = i;
			break;
		}
	}
	//	cout << "id = " << id << endl;
	char exp_sign = a.at(id + 1);
	string middle = a.substr(3, id - 3);
	//cout << "middle = " << middle << " id = " << id << endl;
	string last = a.substr(id + 1, size);
	stringstream ss;
	int exp;
	ss << last;
	ss >> exp;
	//cout <<"exp = "<< exp << endl;
	string ans;

	if (sign == '-') {
		ans.append("-");
	}
	if (exp < 0) {
		ans.append("0.");
		for (int i = 0; i < -exp - 1; i++) {
			ans.append("0");
		}
		ans += c1;
		ans.append(middle);
	}
	else {
		ans += c1;
		int m_size = middle.size();
		if (m_size >= exp) {
			int i;
			for (i = 0; i < exp; i++) {
				ans += middle.at(i);
			}
			ans += '.';
			for (int j = i; j < m_size; j++) {
				ans += middle.at(j);
			}
		}
		else {
			ans.append(middle);
			for (int k = 0; k < exp - m_size; k++) {
				ans += '0';
			}
		}
	}
	//cout << middle << endl;
	cout << ans << endl;
}