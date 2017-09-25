#include<iostream>
#include<string>
#include<vector>
using namespace std;
string map[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
int main() {
	string a;
	cin >> a;
	int size = a.length();
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a.at(i) - '0';
	}
	//cout << "sum = " << sum << endl;
	vector<string> ans;
	int temp = sum;
	while (temp != 0) {
		ans.push_back(map[temp % 10]);
		temp /= 10;
	}
	if (sum == 0) {
		cout << "ling" << endl;
	}
	else {
		int l = ans.size();
		for (int i = l - 1; i > 0; i--) {
			cout << ans[i] << " ";
		}
		cout << ans[0] << endl;
	}
}