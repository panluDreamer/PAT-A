#include<iostream>
#include<cmath>
using namespace std;
int main() {
	long int num;
	cin >> num;
	int len = 0, first = 0;
	int sq = sqrt(1.0*num);
	for (int i = 2; i <=sq; i++) {//i<=sq
		long int temp = 1;
		long int j = i;
		while (1) {
			temp *= j;
			if (num%temp != 0) {
				break;
			}
			if (j - i + 1 > len) {
				first = i;
				len = j - i + 1;
			}
			j++;
		}
	}
	if (len == 0) {
		cout << "1" << endl;
		cout << num << endl;
	}
	else {
		cout << len << endl;
		for (int i = 0; i < len; i++) {
			cout << first;
			if (i != len - 1) {
				cout << "*";
			}
			first++;
		}
	}
}