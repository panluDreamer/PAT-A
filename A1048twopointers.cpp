#include<iostream>
#include<algorithm>
using namespace std;
int buf[100010];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		cin >> buf[i];
	}
	sort(buf, buf + n);
	int i = 0, j = n - 1;
	while (i < j) {
		if (buf[i] + buf[j] == m) break;
		else if (buf[i] + buf[j] > m) { 
			j--; 
		}
		else {
			i++;
		}
	}
	if (i < j) {
		cout << buf[i] << " " << buf[j];
	}
	else {
		cout << "No Solution";
	}
	return 0;
}