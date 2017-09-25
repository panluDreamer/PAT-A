/**
*三维数组加广度优先搜索(BFS)
*/
#include<iostream>
#include<queue>
using namespace std;
int buf[1290][130][65] = { 0 };
bool inqueue[1290][130][65] = { false };
int m, n, l, t;
int ans = 0;
int pos[6][3] = { 0,0,1,//up
				  0,0,-1,//down
				  0,-1,0,//left
				  0,1,0,//right
				 -1,0,0,//forward
				  1,0,0//back
};
struct position {
	int x;
	int y;
	int z;
};
//int countNum = 0;
bool checkPos(position p) {
	if (p.x < 0 || p.x >= m || p.y < 0 || p.y >= n || p.z < 0 || p.z >= l) {
		return false;
	}
	return true;
}
void bfs(position s, int &temp) {
	queue<position> q;
	q.push(s);
	inqueue[s.x][s.y][s.z] = true;
	temp++;
	//cout << "inBfs" << endl;
	while (!q.empty()) {
		position front = q.front();
		//countNum++;
		//cout << "countNum=" << countNum << endl;
		q.pop();
		position next;
		for (int i = 0; i < 6; i++) {
			next.x = front.x + pos[i][0];
			next.y = front.y + pos[i][1];
			next.z = front.z + pos[i][2];
			if (checkPos(next) == true
				&& (inqueue[next.x][next.y][next.z] == false)
				&& buf[next.x][next.y][next.z] == 1) {
				q.push(next);
				inqueue[next.x][next.y][next.z] = true;
				temp++;
			}
		}
	}
}
void bfsImage() {
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (inqueue[i][j][k] == false && buf[i][j][k] == 1) {
					//	cout << "curr:i=" << i << " j=" << j << " k=" << k << endl;
					position s;
					s.x = i;
					s.y = j;
					s.z = k;
					int temp = 0;
					bfs(s, temp);
					//cout << "temp = " << temp << endl;
					if (temp >= t) {
						ans += temp;
					}
				}
			}
		}
	}
}
int main() {
	cin >> m >> n >> l >> t;
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> buf[i][j][k];
			}
		}
	}
	//for (int i = 0; i < 6; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		cout << pos[i][j] << " ";
	//	}
	//	cout << endl;
//	}
//	cout << "bfs:" << endl;
	bfsImage();
	cout << ans << endl;
}

