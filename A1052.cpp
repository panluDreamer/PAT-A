#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct node {
	int add;
	int data;
	int next;
	bool flag;
};
node buf[100005];
bool cmp(node &a, node &b) {
	if (a.flag == 0 || b.flag == 0) {
		return a.flag > b.flag;
	}
	else {
		return a.data < b.data;
	}
}
int main() {
	int n, head;
	scanf("%d %d", &n, &head);
	node temp;
	//while (n--) {
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &temp.add, &temp.data, &temp.next);
		temp.flag = 0;
		buf[temp.add] = temp;
	}
	//}

	int index = head;
	int count = 0;
	while (index != -1) {
		buf[index].flag = 1;
		count++;
		index = buf[index].next;
	}
	if (count == 0) {//ÌØÊâÅÐ¶Ï
		printf("0 -1");
	}
	else {
		sort(buf, buf + 100005, cmp);
		printf("%d %05d\n", count, buf[0].add);
		for (int i = 0; i < count - 1; i++) {
			printf("%05d %d %05d\n", buf[i].add, buf[i].data, buf[i + 1].add);
		}
		printf("%05d %d -1", buf[count - 1].add, buf[count - 1].data);
	}
}
