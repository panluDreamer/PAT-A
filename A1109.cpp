/**
*3,4测试点答案错误!!!
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
struct people {
	string name;
	int height;
};
const int maxn = 10010;
people buf[maxn];
people row[1010];
vector<people> ans[12];
int ans_index = 0;
bool cmp(people &a, people &b) {
	if (a.height != b.height) {
		return a.height < b.height;
	}
	else {
		return a.name < b.name;
	}
}
bool cmp2(people &a, people &b) {
	if (a.height != b.height) {
		return a.height > b.height;
	}
	else {
		return a.name < b.name;
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	int r = n / k;
	for (int i = 0; i < n;i++) {
		cin >> buf[i].name >> buf[i].height;
	}
	sort(buf, buf + n, cmp);
	//cout << "sorted:" << endl;
	//for (int i = 0; i < n;i++) {
	//	cout << buf[i].name << " " << buf[i].height << endl;
	//}
	int remain = n;
	for (int step = 0; step < 1005;step++) {
		if (remain < 2 * r) {//the last row
			sort(buf + step*r, buf + n, cmp2);
			int start_index = step*r;
			int end_index = n;
			queue<people> q;
			stack<people> st;
			q.push(buf[start_index]);
			for (int i = start_index + 1; i < end_index; i++) {
				st.push(buf[i]);
				i++;
				if (i < end_index) {
					q.push(buf[i]);
				}
			}
			while (!st.empty()) {
				ans[ans_index].push_back(st.top());
				st.pop();
			}
			while (!q.empty()) {
				ans[ans_index].push_back(q.front());
				q.pop();
			}
			ans_index++;
			remain = 0;
			break;
		}
		else {//处理一行
			sort(buf + step*r, buf + step*r + r, cmp2);
			int start_index = step*r;
			int end_index = step*r + r;
			queue<people> q;
			stack<people> st;
			q.push(buf[start_index]);
			for (int i = start_index + 1; i < end_index;i++) {
				st.push(buf[i]);
				i++;
				if (i < end_index) {
					q.push(buf[i]);
				}
			}
			while (!st.empty()) {
				ans[ans_index].push_back(st.top());
				st.pop();
			}
			while (!q.empty()) {
				ans[ans_index].push_back(q.front());
				q.pop();
			}
			ans_index++;
			remain -= r;
		}
	}
	//cout << "after:" << endl;
	//for (int i = 0; i < n; i++) {
	//	cout << buf[i].name << " " << buf[i].height << endl;
	//}
	//cout << "ans:" << endl;
	for (int i = ans_index - 1; i >= 0; i--) {
		int s = ans[i].size();
		for (int j = 0; j < s;j++) {
			cout << ans[i].at(j).name;
			if (j != s - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

}
