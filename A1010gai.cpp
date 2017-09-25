//Radix 二分法
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long mp[256];
long long inf = ((long long)1 << 63) - 1;
void init() {
	for (char c = '0'; c <= '9';c++) {
		mp[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z';c++) {
		mp[c] = c - 'a' + 10;
	}
}
long long convertToTen(string a,long long radix,long long t) {
	long long ans = 0;
	int len = a.length();
	for (int i = 0; i < len;i++) {
		ans = ans*radix + mp[a.at(i)];
		if (ans<0 || ans>t) return -1;//溢出或超过N1的十进制
	}
	return ans;
}
int cmp(string n2,long long radix,long long t) {//N2的十进制与t比较
	int len = n2.length();
	long long num = convertToTen(n2, radix, t);
	if (num < 0) {
		return 1;
	}
	if (t > num) {
		return -1;
	}
	else if (t == num) return 0;
	else return 1;
}
long long binary(string n2,long long left,long long right,long long t) {
	long long mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(n2, mid, t);
		if (flag == 0) {
			return mid;
		}
		else if (flag == -1) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}
int findMaxDigit(string n2) {
	int ans = -1, len = n2.length();
	for (int i = 0; i < len;i++) {
		if (mp[n2.at(i)] > ans) {
			ans = mp[n2.at(i)];
		}
	}
	return ans + 1;
}
int main() {
	string n1, n2;
	int tag, radix;
	init();
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2) {
		swap(n1, n2);
	}
	long long t = convertToTen(n1, radix, inf);
	long long low = findMaxDigit(n2);
	long long high = max(low, t) + 1;
	long long ans = binary(n2, low, high, t);
	if (ans == -1) cout << "Impossible" << endl;
	else cout << ans << endl;
	return 0;
}