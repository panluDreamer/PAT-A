#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int SIZE = 1000000007;
int pnum[100010] = { 0 }, tnum[100010] = { 0 };
string a;
void init() {
	int size = a.length();
	int temp = 0;
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (a.at(i) == 'P') {
			temp++;
		}
		pnum[index++] = temp;
	}
	temp = 0;
	index = size - 1;
	for (int i = size - 1; i >= 0; i--) {
		if (a.at(i) == 'T') {
			temp++;
		}
		tnum[index--] = temp;
	}
}
int main() {
	cin >> a;
	init();
	int num = 0;
	int s = a.length();
	for (int i = 0; i < s; i++) {
		if (a.at(i) == 'A') {
			num = (num + pnum[i] * tnum[i]) % SIZE;//每次累加之后都要取余
		}
	}
	cout << num << endl;
}