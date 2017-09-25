#include<iostream>
#include<sstream>
#include<string>
using namespace std;
char *map[9] = { "","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi" };
char *map_num[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string convert(char temp);
int main() {
	int num;
	cin >> num;
	string a;
	stringstream s;
	s << num;
	a = s.str();
	//cout << a.length() << endl;
	//cout << a << endl;
	if (num == 0) {
		cout << "ling";
		return 0;
	}

	if (num < 0) {
		cout << "Fu";
		int len = a.length() - 1;
		for (int i = 1; i <= len - 1; i++) {
			if (a[i] != '0') {
				cout << " " << convert(a[i]) << " " << map[len - i];
			}
			else {
				cout << " " << convert(a[i]);
			}

		}
		if (a[len] != '0') {
			cout << " " << convert(a[len]);
		}
		else {
		}

	}
	else {
		int len = a.length();
		cout << convert(a[0]) << " " << map[len - 1];
		for (int i = 1; i < len - 1; i++) {
			if (a[i] != '0') {
				cout << " " << convert(a[i]) << " " << map[len - i - 1];
			}
			else {
				cout << " " << convert(a[i]);
				//cout << " " << map[len - i - 1];
			}
		}
		if (a[len - 1] != '0') {
			cout << " " << convert(a[len - 1]);
		}
		else {
		}

	}

}
string convert(char temp) {
	return map_num[temp - '0'];
	/*switch (temp)
	{
	case '0': {
		return map_num[0]; break;
	}
	case '1': {return map_num[1]; break; }
	case '2': {return map_num[2]; break; }
	case '3': {return map_num[3]; break; }
	case '4': {return map_num[4]; break; }
	case '5': {return map_num[5]; break; }
	case '6': {return map_num[6]; break; }
	case '7': {return map_num[7]; break; }
	case '8': {return map_num[8]; break; }
	case '9': {return map_num[9]; break; }

	default:
		break;
	}*/

}