#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct position {
	int x;
	int y;
};
int pos[4][2] = {
	0,1, //右
	1,0,//下
	0,-1,//左
	-1,0//上
};
int num;
int m, n;
const int maxn = 10010;
int buf[maxn];
int **a;
bool cmp(int a, int b) {
	return a > b;
}
bool checkPos(position p) {
	if (p.x < 0 || p.x >= m || p.y < 0 || p.y >= n || a[p.x][p.y] != -1) {
		return false;
	}
	return true;
}
void findmn(int s) {
	if (s*s == num) {
		m = s;
		n = s;
	}
	else {
		m = s + 1;
		n = s;
		while (num%m != 0) {
			m++;
		}
		while (num%n != 0) {
			n--;
		}
	}

}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> buf[i];
	}
	int s = sqrt(1.0*num);
	//cout << "sqrt = " << s << endl;
	findmn(s);
	//cout << "m = " << m << " n = " << n << endl;
	a = new int*[m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = -1;
		}
	}
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
//	}
	sort(buf, buf + num, cmp);
	//fill in array
	int index = 0;
	int count = 0;
	position start;
	start.x = 0;
	start.y = 0;
	a[start.x][start.y] = buf[index++];
	position next;
	int dir = 0;//控制方向
	while (index < num) {
		//填充方式：先向右一直填，
		//不行时再向下一直填，否则向左一直填，否则向上一直填，否则向右一直填,.....
		next.x = start.x + pos[dir][0];//右
		next.y = start.y + pos[dir][1];
		if (checkPos(next)) {
			a[next.x][next.y] = buf[index++];
			start = next;
		}
		else {
			dir = (dir + 1) % 4;//右->下->左->上->右->下->....
		}
	}
	//cout << "filled:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
			if (j != n - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}