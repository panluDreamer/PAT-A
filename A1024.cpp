#include<iostream>//single number
#include<string>
#include<sstream>
#include<vector>
using namespace std;
template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}
string intToString(const long int &num) {
	string temp;
	stringstream ss;
	ss << num;
	temp = ss.str();
	return temp;
}
bool isPalin(string a) {
	int size = a.size();
	bool flag = true;
	for (int i = 0; i < size / 2; i++) {
		if (a.at(i) != a.at(size - i - 1)) {
			flag = false;
			break;
		}
	}
	return flag;
}
/**
*必须使用string加法，否则测试点6,8通不过，因为转为数字后，大小超过long int的最大值
**/
string add_string(string a, string b) {
	vector<char> temp;
	int carry = 0;
	int size = a.size();
	int t;
	char c;
	for (int i = size - 1; i >= 0; i--) {
		t = a.at(i) - '0' + b.at(i) - '0' + carry;
		carry = t / 10;
		c = t % 10 + '0';
		temp.push_back(c);
	}
	if (carry != 0) {
		c = carry + '0';
		temp.push_back(c);
	}
	int l = temp.size();
	string ans;
	for (int i = l - 1; i >= 0; i--) {
		ans += temp.at(i);
	}
	return ans;
}
int main() {
	string n;
	int k;
	int step = 1;
	cin >> n >> k;
	if (n.size() == 1 || isPalin(n)) {
		cout << n << endl;
		cout << "0" << endl;
		return 0;
	}
	string p = n;
	string after;
	while (step <= k) {
		string temp;
		int size = p.length();
		for (int i = size - 1; i >= 0; i--) {
			temp += p.at(i);
		}
		//	cout << "p=" << p << " temp=" << temp << endl;
			//long int a = stringToNum<long int>(p);
			//long int b = stringToNum<long int>(temp);
		//	long int c = a + b;
			// after = intToString(c);
		after = add_string(p, temp);
		if (isPalin(after)) {
			break;
		}
		else {
			p = after;
		}
		step++;
	}
	if (step > k) {
		cout << p << endl;
		cout << k << endl;
	}
	else {
		cout << after << endl;
		cout << step << endl;
	}

}