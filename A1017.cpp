//体会如何模拟顾客在多个窗口的排队
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int K = 105;
struct customer {
	int arriveTime;
	int serveTime;
};
int convert(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
bool cmp(customer &a, customer &b) {
	return a.arriveTime < b.arriveTime;
}
int endTime[K];

customer newCustomer;
int main() {
	int n, w;
	vector<customer> vec;
	scanf("%d%d", &n, &w);
	int h, m, s, serve;
	int arriveTime, serveTime, totalTime = 0;
	int stTime = convert(8, 0, 0);
	int edTime = convert(17, 0, 0);
	for (int i = 0; i < w; i++) {
		endTime[i] = stTime;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d:%d:%d %d", &h, &m, &s, &serve);
		arriveTime = convert(h, m, s);
		if (arriveTime > edTime) {
			continue;
		}
		newCustomer.arriveTime = arriveTime;
		newCustomer.serveTime = serve > 60 ? 3600 : serve * 60;
		vec.push_back(newCustomer);
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size(); i++) {
		int index = -1, minEndTime = 100000000;
		for (int j = 0; j < w; j++) {
			if (endTime[j] < minEndTime) {
				minEndTime = endTime[j];
				index = j;
			}
		}
		if (vec[i].arriveTime >= minEndTime) {
			endTime[index] = vec[i].arriveTime + vec[i].serveTime;
		}
		else {
			totalTime += minEndTime - vec[i].arriveTime;
			endTime[index] += vec[i].serveTime;
		}
	}
	printf("%.1f", totalTime / 60.0 / vec.size());
	return 0;
}