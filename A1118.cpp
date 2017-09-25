#include<iostream>
using namespace std;
const int maxn = 10005;
int father[maxn];
int birdHash[maxn] = { 0 };
bool isRoot[maxn] = { false };
int cnt[maxn] = { 0 };
int findFather(int a) {
	if (a == father[a]) {//写成了=号，应该是==
		return a;
	}
	else {
		int f = findFather(father[a]);
		father[a] = f;
		return f;
	}
}

void Union(int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);
	if (fa != fb) {
		father[fa] = fb;
	}
}
void init() {
	for (int i = 1; i <= maxn; i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}
int main() {
	int n, id, temp;
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k >> id;
		birdHash[id] = 1;
		for (int j = 0; j < k - 1; j++) {
			cin >> temp;
			Union(id, temp);
			birdHash[temp] = 1;
		}
	}
	int treenum = 0, birdnum = 0;
	for (int i = 1; i <= maxn; i++) {
		if (birdHash[i] == 1) {
			if (i == findFather(i)) {
				isRoot[i] = true;
			}
			birdnum++;
		}
	}
	for (int i = 1; i <= maxn; i++) {
		if (isRoot[i]) {
			treenum++;
		}
	}

	cout << treenum <<" "<< birdnum << endl;
	//cout << "father array: ";
	//for (int i = 1; i <= birdnum;i++) {
	//	cout << father[i] << " ";
	//}
	 
	int q, a, b;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (findFather(a) == findFather(b)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}