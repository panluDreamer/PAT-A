/**
*此题如果用cin输入，有一个测试点会超时，改用scanf输入，可以通过
*/
#include<cstdio>
#include<map>
using namespace std;
map<int, int> numToId;
map<int, int> idToInt;
int numcount = 0;
int buf[805][605] = { 0 };
int hashTable[480010];
int change(int num) {//返回数字对应的id
	if (numToId.find(num) != numToId.end()) {
		return numToId[num];
	}
	else {
		numToId[num] = numcount;
		idToInt[numcount] = num;
		return numcount++;
	}
}
int main() {
	int m, n;
	//cin >> m >> n;//n行m列
	scanf("%d%d", &m, &n);
	int id;
	int ans_count = -1;
	int ans_id = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cin >> buf[i][j];
			scanf("%d", &buf[i][j]);
			id = change(buf[i][j]);
			hashTable[id]++;
			if (hashTable[id] > ans_count) {
				ans_count = hashTable[id];
				ans_id = id;
			}
		}
	}
	//cout << "numcount:" << numcount << endl;
	//double half = m*n / 2;
	//int ans;
	//for (int i = 0; i < numcount; i++) {
//		if (hashTable[i] > half) {
//			ans = i;
//			break;
//		}
//	}
	//cout << idToInt[ans_id] << endl;
	printf("%d\n", idToInt[ans_id]);

}