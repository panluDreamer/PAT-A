#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
map<string, vector<int>> mp;
int main() {
	string a;
	cin >> a;
	vector<int> v;
	mp[a].push_back(888);
	string b;
	cin >> b;
	mp[b].push_back(520);
	cin >> b;
	mp[b].push_back(8888);
	cin >> b;
	vector<int> ans;
	ans = mp[b];
	for (int i = 0; i < ans.size();i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cout << "map.size() = " << mp.size() << endl;
}