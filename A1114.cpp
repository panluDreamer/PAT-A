#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;
struct node {
	int estate;
	int area;
};
struct ans {
	int id;
	int member;
	double avg_set;
	double avg_area;
};
const int maxn = 3000;
int G[maxn][maxn];
map<int, int> idToIndex;
map<int, int> indexToId;
//vector<int>Adj[maxn];
node buf[maxn];
bool inq[maxn] = { false };
bool exist[maxn] = { false };
ans res[maxn];
int index = 0;
int family = 0;
int numPeople = 0;
int change(int id) {
	if (idToIndex.find(id) != idToIndex.end()) {
		return idToIndex[id];
	}
	else {
		idToIndex[id] = numPeople;
		indexToId[numPeople] = id;
		numPeople++;
		return idToIndex[id];
	}

}
void bfs(int index, int &num, int &totalSet, int &totalArea, int &minId) {
	queue<int> q;
	q.push(index);
	inq[index] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		num++;
		totalSet += buf[front].estate;
		totalArea += buf[front].area;
		if (indexToId[front] < minId) {
			minId = indexToId[front];
		}
		for (int i = 0; i < numPeople; i++) {
			if (inq[i] == false && G[front][i] == 1) {
				q.push(i);
				inq[i] = true;
			}
		}
	}
}
void bfsGraph() {
	for (int i = 0; i < numPeople; i++) {
		//
		if (exist[i] == true && inq[i] == false) {
			family++;
			int num = 0, totalSet = 0, totalArea = 0, minId = 999999;//Ä³Ò»Á¬Í¨¿é
			bfs(i, num, totalSet, totalArea, minId);
			//printf("num = %d,avgSet = %.3f,avgArea = %.3f,minId = %d\n", num, 1.0*totalSet/num, 1.0*totalArea/num, minId);
			ans temp;
			temp.id = minId;
			temp.member = num;
			temp.avg_set = 1.0*totalSet / num;
			temp.avg_area = 1.0*totalArea / num;
			res[index++] = temp;
		}
	}
}
bool cmp(ans a, ans b) {
	if (a.avg_area != b.avg_area) {
		return a.avg_area > b.avg_area;
	}
	else {
		return a.avg_set < b.avg_set;
	}
}
int main() {
	fill(G[0], G[0] + maxn*maxn, 0);
	int n;
	scanf("%d", &n);

	int id1, id2, id3, k;
	int estate, area;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &id1, &id2, &id3);
		int index1 = change(id1);
		int index2 = change(id2);
		int index3 = change(id3);
		exist[index1] = true;
		if (id2 != -1) {
			exist[index2] = true;
			//Adj[id1].push_back(id2);
		//	Adj[id2].push_back(id1);
			G[index1][index2] = 1;
			G[index2][index1] = 1;
		}
		if (id3 != -1) {
			exist[index3] = true;
			//Adj[id1].push_back(id3);
			//Adj[id3].push_back(id1);
			G[index1][index3] = 1;
			G[index3][index1] = 1;
		}
		scanf("%d", &k);
		int tempid;
		for (int i = 0; i < k; i++) {
			scanf("%d", &tempid);
			int tempIndex = change(tempid);
			//Adj[id1].push_back(tempid);
			//Adj[tempid].push_back(id1);
			G[index1][tempIndex] = 1;
			G[tempIndex][index1] = 1;
			exist[tempIndex] = true;
		}
		scanf("%d%d", &estate, &area);
		buf[index1].estate = estate;
		buf[index1].area = area;
	}
	bfsGraph();
	printf("%d\n", family);
	sort(res, res + index, cmp);
	for (int i = 0; i < index; i++) {
		printf("%04d %d %.3f %.3f\n",
			res[i].id, res[i].member, res[i].avg_set, res[i].avg_area);
	}
	return 0;
}