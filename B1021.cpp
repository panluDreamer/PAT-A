#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int map[10];
	fill(map, map + 10, 0);
	string a;
	cin >> a;
	int size = a.length();
	for (int i = 0; i < size; i++) {
		map[a.at(i) - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (map[i] != 0) {
			cout << i << ":" << map[i] << endl;
		}
	}
}