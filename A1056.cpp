#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1010;
struct mouse {
	double weight;
	int rank;
};
mouse buf[maxn];
queue<int> q;
int main() {
	int np, ng;
	int temp;
	cin >> np >> ng;
	for (int i = 0; i < np; i++) {
		cin >> buf[i].weight;
	}
	for (int i = 0; i < np; i++) {
		cin >> temp;
		q.push(temp);
	}
	int nowMice = np, group;
	while (q.size() > 1) {
		if (nowMice%ng == 0) {
			group = nowMice / ng;
		}
		else {
			group = nowMice / ng + 1;
		}
		for (int i = 0; i < group; i++) {
			int k = q.front();//存放该组质量最大的老鼠编号
			for (int j = 0; j < ng; j++) {
				if (i*ng + j >= nowMice) break;//当最后一组不足ng个元素时
				int front = q.front();
				if (buf[front].weight > buf[k].weight) {
					k = front;
				}
				buf[front].rank = group + 1;//对该轮老鼠的排名都赋值为group+1,晋级的老鼠后面会得到新的排名
				q.pop();
			}
			q.push(k);
		}
		nowMice = group;
	}
	buf[q.front()].rank = 1;
	for (int i = 0; i < np; i++) {
		cout << buf[i].rank;
		if (i != np - 1) cout << " ";
	}
}