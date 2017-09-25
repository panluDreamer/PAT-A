#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
const int maxn = 1010;
int father[maxn];
vector<int> buf[maxn];
set<int> hobby;
map<int, int> mp;
int count[maxn] = { 0 };
bool cmp(int a, int b) {
	return a > b;
}
void init() {
	for (int i = 1; i <= maxn; i++) {
		father[i] = i;
	}
}
int findFather(int v) {
	if (v == father[v]) {
		return v;
	}
	else {
		int f = findFather(father[v]);
		father[v] = f;
		return f;
	}
}
void union_num(int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);
	if (fa != fb) {
		father[fa] = fb;
	}
}
int main() {
	int n;
	scanf("%d", &n);//3ºÅ²âÊÔµãÒì³£ÍË³ö,n==1000
	init();
	int m;
	int temp;
	int first;
	for (int i = 0; i < n; i++) {
		scanf("%d:", &m);
		scanf("%d", &first);
		buf[i].push_back(first);
		hobby.insert(first);
		for (int j = 1; j < m; j++) {
			scanf("%d", &temp);
			hobby.insert(temp);
			union_num(first, temp);
			buf[i].push_back(temp);
		}
	}
	for (int i = 0; i < n; i++) {
		//printf("at(0) = %d", buf[i].at(0));
		int f = findFather(buf[i].at(0));
		//printf("  f = %d\n", f);
		mp[f]++;
	}
	//printf("hobby.size = %d\n" , hobby.size());
	int clusterCount = 0;
	set<int>::iterator it;
	for (it = hobby.begin(); it != hobby.end(); it++) {
		int id = *it;
		if (id == findFather(id)) {
			clusterCount++;
		}
	}
	printf("%d\n", clusterCount);
	int ans_size = mp.size();
	//printf("map size = %d\n", mp.size());
	map<int, int>::iterator mpit;
	vector<int>res;
	for (mpit = mp.begin(); mpit != mp.end(); mpit++) {
		//	printf("first = %d, second=%d\n", mpit->first, mpit->second);
		res.push_back(mpit->second);
	}
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < ans_size; i++) {
		cout << res.at(i);
		if (i != ans_size - 1) {
			cout << " ";
		}
	}
	cout << endl;
}