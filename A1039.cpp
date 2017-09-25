#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
map<string, set<int>> mp;
bool cmp(int a, int b) {
	return a < b;
}
int main() {
	int n, k;
	int courseId, num;
	cin >> n >> k;
	/*if (n==40000) {//³¬Ê±
		cout << "hahahha" << endl;
		return 0;
	}*/
	string name;
	for (int i = 0; i < k; i++) {
		cin >> courseId >> num;
		for (int j = 0; j < num; j++) {
			cin >> name;
			mp[name].insert(courseId);
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> name;
		cout << name << " " << mp[name].size();
		if (mp[name].size() != 0) {
			cout << " ";
			//sort(mp[name].begin(), mp[name].end(), cmp);
			/*for (int j = 0; j < mp[name].size(); j++) {
				if (j != mp[name].size() - 1) {
					cout << mp[name][j] << " ";
				}
				else {
					cout << mp[name][j] << endl;
				}
			}*/
			set<int>::iterator it, it2;
			for (it = mp[name].begin(); it != mp[name].end(); it++) {
				it2 = it;
				if ((++it2) != mp[name].end()) {
					cout << *it << " ";
				}
				else {
					cout << *it << endl;
				}
			}
		}
		else {
			cout << endl;
		}
	}
}