#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int a[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	int count = 0, i = n - 1, j = n - 1;
	long long int maxNum, minNum;
	while (i != 0) {
		minNum = a[j];
		int index = j;
		int temp = 0;
		while (index >= 0 && a[index] <= minNum*p) {
			temp++;
			index--;
		}
		if (temp > count) {
			count = temp;
		}
		i = index;
		j--;
	}
	cout << count << endl;
}