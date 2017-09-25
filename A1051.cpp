#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int m, n, k;
	vector<int> test;
	stack<int> st;
	int temp;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		test.clear();
		while (!st.empty()) {
			st.pop();
		}
		for (int j = 0; j < n; j++) {
			cin >> temp;
			test.push_back(temp);
		}
		int idx = 1, t = 0;
		while ((st.size() < m) && (idx <= n) && (t < n)) {//×¢Òâst.size()<m £¬ ²»ÊÇ<=m
			st.push(idx);
			if (st.top() == test[t]) {
				do {
					if (st.top() == test[t]) {
						st.pop();
						t++;
					}
					else {
						break;
					}
				} while (st.size() != 0);
			}
			idx++;
		}
		if (st.size() == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}