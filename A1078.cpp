#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int hashTable[maxn] = { -1 };
int Tsize;
bool isPrime(int a) {
	if (a == 1) {//判断素数时，不要漏掉1的特殊情况
		return false;
	}
	bool flag = true;
	for (int i = 2; i <= sqrt(1.0*a); i++) {
		if (a%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}
int find_min(int num) {
	while (1) {
		num++;
		if (isPrime(num) == true) {
			break;
		}
	}
	return num;
}
int insert_hashTable(int num) {
	int index_pre = num%Tsize;
	int index = index_pre;
	int probe = 1;
	int pos = -1;
	int step = 0;
	while (step < Tsize) {//当探测次数为Tsize时，可以判定无法找到合适位置
		if (hashTable[index] == -1) {
			hashTable[index] = num;
			pos = index;
			break;
		}
		else {
			index = (index_pre+ probe*probe) % Tsize;//探测方法不是index+probe*probe!!!
			probe++;
		}
		step++;
	}
	return pos;
}
int main() {
	int s, n;
	cin >> s >> n;
	if (isPrime(s)) {
		Tsize = s;
	}
	else {
		Tsize = find_min(s);
	}
	fill(hashTable, hashTable + maxn, -1);
	//cout << "Tsize = " << Tsize << endl;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		int pos = insert_hashTable(num);
		if (pos == -1) {
			cout << "-";
		}
		else {
			cout << pos;
		}
		if (i != n - 1) {
			cout << " ";
		}
	}
}