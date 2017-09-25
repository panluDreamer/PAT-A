#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
struct node {
	int addr;
	int data;
	int next;
};
const int maxn = 100010;
node buf[maxn];
stack<node> st;
vector<node> ans;
int main() {
	int a, n, k, turn;
	scanf("%d%d%d", &a, &n, &k);
	//if (n == 0) {
	//	while (true);
		//printf("%05d 0 -1");
//		return 0;
//	}
	int temp_addr, temp_data, temp_next;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &temp_addr, &temp_data, &temp_next);
		buf[temp_addr].addr = temp_addr;
		buf[temp_addr].data = temp_data;
		buf[temp_addr].next = temp_next;
	}
	turn = n / k;
	int index = a;
	for (int i = 0; i < turn; i++) {
		for (int j = 0; j < k; j++) {
			st.push(buf[index]);
			index = buf[index].next;
		}
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
	}
	//printf("index = %05d\n", index);
	if (index != -1) {
		int size = ans.size();
		for (int i = 0; i < size - 1; i++) {
			printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i + 1].addr);
		}
		printf("%05d %d %05d\n", ans[size - 1].addr, ans[size - 1].data, index);
		while (index != -1) {
			if (buf[index].next != -1) {
				printf("%05d %d %05d\n", buf[index].addr, buf[index].data, buf[index].next);
			}
			else {
				printf("%05d %d -1", buf[index].addr, buf[index].data);
			}
			index = buf[index].next;
		}
	}
	else {
		int size = ans.size();
		for (int i = 0; i < size - 1; i++) {
			printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i + 1].addr);
		}
		printf("%05d %d -1", ans[size - 1].addr, ans[size - 1].data);
	}
}

/*AC代码
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
*/