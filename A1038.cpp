#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 10010;
string buf[maxn];
bool cmp(string a, string b) {//̰�Ĳ��Բ�����
	return a + b < b + a;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
	}
	sort(buf, buf + n, cmp);
	string ans;
	for (int i = 0; i < n; i++) {
		ans += buf[i];
	}
	int len = ans.length();
	int index = 0;
	//string::iterator it;
	//while (ans.size() != 0 && ans[0] == '0') {//ȥ��ǰ����,(�����Ϸ���30��)
	//	ans.erase(ans.begin());
//	}
	//cout << "ans = " << ans << endl;
	//cout << "len=" << len << endl;
	for (int i = 0; i < len; i++) {//�ҵ���һ������λ��(3�Ų��Ե����ȥ)
		if (ans[i] != '0') {
			index = i;
			break;
		}
	}
	//cout << "index = " << index << endl;
	if (index == 0) {
		cout << "0" << endl;
	}
	else {
		string sub = ans.substr(index, len);
		cout << sub << endl;
	}
}