#include<iostream>
#include<set>
using namespace std;
const int maxn = 100010;
int buf[maxn];
int le[maxn] = { 0 };//记录当前位置左边比自己大的数的个数
int ri[maxn] = { 0 };//记录当前位置右边比自己小的数的个数
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> buf[i];
	}
	int left_max = -1, right_min = 1000001111;
	
	left_max = buf[0];
	for (int i = 1; i < n;i++) {
		if (buf[i] < left_max) {
			le[i] = 1;
		}
		else {
			left_max = buf[i];
		}
	}
	right_min = buf[n - 1];
	for (int i = n - 2; i >= 0;i--) {
		if (buf[i] > right_min) {
			ri[i] = 1;
		}
		else {
			right_min = buf[i];
		}
	}
	set<int> ans;
	for (int i = 0; i < n;i++) {
		if (le[i] == 0 && ri[i] == 0) {
			ans.insert(buf[i]);
		}
	}
	set<int>::iterator it;
	int count = 0;
	int size = ans.size();
	cout << size << endl;
	for (it = ans.begin(); it != ans.end();it++) {
		count++;
		cout << *it;
		if (count != size) {
			cout << " ";
		}
	}
	cout << endl;//换行写在这里,当size=0时，要输出一个空行,然后再换行
}

