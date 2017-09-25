#include<iostream>
#include<set>
#include<iomanip>
using namespace std;
const int maxn = 55;
set<int> buf[maxn];
int main() {
	int n;
	int m, temp;
	cin >> n;
	for (int i = 1; i <= n;i++) {
		cin >> m;
		for (int j = 0; j < m;j++) {
			cin >> temp;
			buf[i].insert(temp);
		}
	}
	int k;
	int s1, s2;
	cin >> k;
	for (int i = 0; i < k;i++) {
		cin >> s1 >> s2;
		int same = 0, total = buf[s1].size();
		set<int>::iterator it;
		for (it = buf[s2].begin(); it != buf[s2].end(); it++) {
			if (buf[s1].find(*it) != buf[s1].end()) {
				same++;
			}
			else {
				total++;
			}
		}
		double ans = same*1.0 / total * 100;
		cout << setiosflags(ios::fixed) << setprecision(1) << ans << "%" << endl;
	}
}