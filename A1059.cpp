#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct factor {
	int x;
	int count;
}fac[100];
vector<int> prime;
void findPrime() {
	bool flag;
	for (int i = 2; i <= 10000; i++) {
		flag = true;
		for (int j = 2; j <= sqrt((double)i); j++) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			prime.push_back(i);
		}
	}
}
int main() {
	long int num, copy;
	cin >> num;
	if (num == 1) {//¿¼ÂÇÌØÊâÇé¿ö,num=1
		cout << "1=1" <<endl;
		return 0;
	}
	copy = num;
	findPrime();
	int size = prime.size();
	//cout << prime[0] << " " << prime[1] << " " << prime[size - 1] << endl;
	int index = 0;
	for (int i = 0; i < size - 1 && num>1; i++) {
		if (num%prime[i] == 0) {
			fac[index].x = prime[i];
			fac[index].count = 0;
			while (num%prime[i] == 0) {
				fac[index].count++;
				num /= prime[i];
			}
			index++;
		}
	}
	if (num != 1) {
		fac[index].x = num;
		fac[index].count = 1;
		index++;
	}
	cout << copy << "=";
	for (int i = 0; i < index - 1; i++) {
		if (fac[i].count != 1) {
			cout << fac[i].x << "^" << fac[i].count << "*";
		}
		else {
			cout << fac[i].x << "*";
		}
	}
	if (fac[index - 1].count == 1) {
		cout << fac[index - 1].x << endl;
	}
	else {
		cout << fac[index - 1].x << "^" << fac[index - 1].count << endl;
	}
}