#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
map<int, set<string>> mp;
int main() {
	int n, k;
	cin >> n >> k;
	string name;
	int num, courseid;
	for (int i = 0; i < n; i++) {
		cin >> name >> num;
		for (int j = 0; j < num; j++) {
			cin >> courseid;
			mp[courseid].insert(name);
		}
	}
	for (int i = 1; i <= k; i++) {
		int size = mp[i].size();
		cout << i << " " << size << endl;
		set<string>::iterator it;
		for (it = mp[i].begin(); it != mp[i].end(); it++) {
			cout << *it << endl;
		}
	}
}