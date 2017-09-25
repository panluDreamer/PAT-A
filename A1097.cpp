#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
struct node {
	int addr;
	int data;
	int next;
};
const int maxn1 = 10010;
const int maxn2 = 100010;
int hash1[maxn1] = { 0 };
node buf[maxn2];
vector<node> ans1;
vector<node> ans2;
int main() {
	int a, n;
	scanf("%d%d", &a, &n);
	int temp_addr, temp_data, temp_next;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &temp_addr, &temp_data, &temp_next);
		buf[temp_addr].addr = temp_addr;
		buf[temp_addr].data = temp_data;
		buf[temp_addr].next = temp_next;
	}
	int index = a;
	while (index != -1) {
		int t = abs(buf[index].data);
		if (hash1[t] == 0) {
			ans1.push_back(buf[index]);
			hash1[t] = 1;
		}
		else {
			ans2.push_back(buf[index]);
		}
		index = buf[index].next;
	}
	int len1 = ans1.size();
	int len2 = ans2.size();
	for (int i = 0; i < len1; i++) {
		if (i != len1 - 1) {
			printf("%05d %d %05d\n", ans1[i].addr, ans1[i].data, ans1[i + 1].addr);
		}
		else {
			printf("%05d %d -1\n", ans1[i].addr, ans1[i].data);
		}
	}
	for (int i = 0; i < len2; i++) {
		if (i != len2 - 1) {
			printf("%05d %d %05d\n", ans2[i].addr, ans2[i].data, ans2[i + 1].addr);
		}
		else {
			printf("%05d %d -1\n", ans2[i].addr, ans2[i].data);
		}
	}
}