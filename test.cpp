#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
struct node {
	int data;
	int addr;
	int next;
};
vector<node> buf;
vector<node> ans;
const int maxn = 100010;
node a[maxn];
int main() {
	int start, n, k;
	scanf("%d%d%d", &start, &n, &k);
	int addr, data, next;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &addr, &data, &next);
		a[addr].addr = addr;
		a[addr].data = data;
		a[addr].next = next;
	}
	node temp;
	int ne = start;
	while (ne != -1) {//除去无效节点
		temp.addr = a[ne].addr;
		temp.data = a[ne].data;
		temp.next = a[ne].next;
		buf.push_back(temp);
		ne = a[ne].next;
	}
	//	printf("buf size = %d\n", buf.size());
	int times = buf.size() / k;
	int index = 0;
	int size = buf.size();
	stack<node> st;
	for (int i = 0; i < times; i++) {
		int num = 0;
		while (num < k) {
			st.push(buf[index++]);
			num++;
		}
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
	}
	for (int i = index; i < size; i++) {
		ans.push_back(buf[i]);
	}
	for (int i = 0; i < size - 1; i++) {
		printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i + 1].addr);
	}
	printf("%05d %d -1\n", ans[size - 1].addr, ans[size - 1].data);
}