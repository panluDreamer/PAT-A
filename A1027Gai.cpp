#include<iostream>
using namespace std;
char map[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };
int main() {
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#";
	cout << map[r / 13] << map[r % 13];
	cout << map[g / 13] << map[g % 13];
	cout << map[b / 13] << map[b % 13];
	return 0;
}