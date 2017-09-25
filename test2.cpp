#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int buf[5][5] =
{
{0,1,0,1,1},
{1,1,1,0,1},
{0,0,0,0,0},
{1,1,0,0,0},
{1,1,1,0,0}
};
int inq[5][5] =
{
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 }
};
struct point {
	int x;
	int y;
	point(int tempx, int tempy) {
		x = tempx;
		y = tempy;
	}
};
vector<point> v;
bool check(point p, int w, int h) {
	if (p.x<0 || p.x>w - 1 || p.y<0 || p.y>h - 1) {
		return false;
	}
	if (buf[p.x][p.y] == 0 || inq[p.x][p.y]) {
		return false;
	}
	return true;
}
int x[8] = {-1,-1,-1,0,0,1,1,1};
int y[8] = {-1,0,1,-1,1,0,-1,1};
void bfs(point p,int w,int h) {
	queue<point> q;
	q.push(p);
	inq[p.x][p.y] = 1;
	while (!q.empty()) {
		point front = q.front();
		q.pop();
		if (buf[front.x][front.y] == 1) {
			v.push_back(front);
		}
		for (int i = 0; i < 8;i++) {
			point temp_point(front.x + x[i], front.y + y[i]);
			if (check(temp_point,w,h)) {
				q.push(temp_point);
				inq[temp_point.x][temp_point.y] = 1;
			}
		}
	}
}
void getzone(point p, int w, int h) {
	bool res = check(p, w, h);
	if (res == false) return;
	v.push_back(p);
	inq[p.x][p.y] = 1;
	point p1(p.x - 1, p.y - 1);
	getzone(p1, w, h);
	point p2(p.x - 1, p.y);
	getzone(p2, w, h);
	point p3(p.x - 1, p.y + 1);
	getzone(p3, w, h);
	point p4(p.x, p.y - 1);
	getzone(p4, w, h);
	point p5(p.x, p.y + 1);
	getzone(p5, w, h);
	point p6(p.x + 1, p.y);
	getzone(p6, w, h);
	point p7(p.x + 1, p.y - 1);
	getzone(p7, w, h);
	point p8(p.x + 1, p.y + 1);
	getzone(p8, w, h);
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << buf[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (inq[i][j] == 0) {
				point p(i, j);
				//getzone(p, 5, 5);
				bfs(p, 5, 5);
				int size = v.size();
				cout << "size=" << size << endl;
				for (int k = 0; k < size; k++) {
					cout << "(x,y):" << v[k].x << "," << v[k].y << endl;
				}
				v.clear();
			}

		}
	}
}