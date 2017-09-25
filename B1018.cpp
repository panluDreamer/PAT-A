#include<iostream>
using namespace std;
int change(char c) {
	if (c == 'B') return 0;
	else if (c == 'C') return 1;
	else return 2;
}
int main() {
	char map[3] = { 'B','C','J' };
	int a[3] = { 0 }, b[3] = { 0 }, count_a[3] = { 0 }, count_b[3] = { 0 };
	int n;
	char t1, t2;
	int k1, k2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		k1 = change(t1);
		k2 = change(t2);
		if (k1 == k2) {
			a[1]++;
			b[1]++;
		}
		else if ((k1 + 1) % 3 == k2) {
			a[0]++;
			b[2]++;
			count_a[k1]++;
		}
		else {
			b[0]++;
			a[2]++;
			count_b[k2]++;
		}
	}
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	cout << b[0] << " " << b[1] << " " << b[2] << endl;
	int id1 = 0, id2 = 0;
	for (int i = 1; i < 3; i++) {
		if (count_a[i] > count_a[id1]) {
			id1 = i;
		}
		if (count_b[i] > count_b[id2]) {
			id2 = i;
		}
	}
	cout << map[id1] << " " << map[id2] << endl;
}