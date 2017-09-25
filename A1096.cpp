#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct E {
	int len;
	int first;
	long int value;
};
vector<E> buf;
bool cmp(E& a, E& b) {
	if (a.len != b.len) {
		return a.len>b.len;
	}
	else {
		return a.first < b.first;
	}
}
long int cal(int f,int len) {
	long int ans = 1;
	for (int i = 0; i < len;i++) {
		ans *= f;
		f++;
	}
	return ans;
}
void init() {
	E a;
	for (int i = 2; i <= 13;i++) {
		for (int j = 1; j <= 14 - i; j++) {
			//c++;
			//cout << "i=" << i << " " << "j=" << j << endl;
			a.first = i;
			a.len = j;
			a.value = cal(i, j);
			buf.push_back(a);
		}
	}

}
int main() {
	init();
	sort(buf.begin(), buf.end(), cmp);
	//cout << buf.size() << endl;
	//cout << buf[4].first<<" "<<buf[4].len<<" "<<buf[4].value << endl;
	long int num;
	cin >> num;
	int ans = -1;
	for (int i = 0; i < buf.size() - 1;i++) {
		if (num%buf[i].value == 0) {
			ans = i;
			break;
		}
	}
	if (ans != -1) {
		int v = buf[ans].first;
		int l = buf[ans].len;
		cout << l << endl;
		for (int i = 0; i < l - 1; i++) {
			cout << v << "*";
			v++;
		}
		cout << v << endl;
	}
}