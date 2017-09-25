//hash
#include<iostream>
using namespace std;
int buf[1010];
int main() {
	int n, m;
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n;i++) {
		cin >> temp;
		buf[temp]++;
	}
	int i;
	for ( i = 0; i < 1010;i++) {
		if (i != (m - i) && buf[i] != 0 && buf[m - i] != 0) {
			cout << i << " " << (m - i);
			break;
		}
		if (i == (m - i) && buf[i] >= 2) {
			cout << i << " " << (m - i);
			break;
		}
	}
	if (i == 1010) {
		cout << "No Solution";
	}
}