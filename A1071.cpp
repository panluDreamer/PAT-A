#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
string a;
const int maxn = 1048580;
char t[maxn];
map<string, int> time_record;//不要用time做名字，否则编译错误
bool check(char c) {
	if ((c >= '0'&&c <= '9') || (c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')) {
		return true;
	}
	return false;
}
string convert(string a) {
	int size = a.size();
	for (int i = 0; i < size;i++) {
		if (a.at(i) >= 'A'&&a.at(i) <= 'Z') {
			a.at(i) = a.at(i) + 32;
	   }
	}
	return a;
}
int main() {
	cin.getline(t, sizeof(t));
	a = t;
	//cout << a << endl;
	int len = a.size();
	int index = 0;
	string temp;
//	cout << "len = " << len << endl;
	while (index < len) {
		if (check(a[index]) == true) {
			temp += a[index];
			index++;
		}
		else {
			if (temp.size() == 0) {
				index++;
			}
			else {
				//cout << "temp = " << temp <<" index="<<index<< endl;
				string con = convert(temp);
				time_record[con]++;
				temp.clear();
				index++;
			}
		}
	}
	if (temp.size() != 0) {
		string con = convert(temp);
		time_record[con]++;
	}
	map<string, int>::iterator it;
	string result;
	int times = -1;
	for (it = time_record.begin(); it != time_record.end(); it++) {
		//cout << it->first << " " << it->second << endl;
		if (it->second > times) {
			times = it->second;
			result = it->first;
		}
		else if (it->second == times) {
			if (it->first < result) {
				times = it->second;
				result = it->first;
			}
		}
	}
	cout << result << " " << times << endl;
}