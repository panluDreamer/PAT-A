#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct R {
	int id;
	char name[12];
	int grade;
};
bool cmp1(R a, R b) {
	return a.id < b.id;
}
bool cmp2(R a, R b) {
	int s = strcmp(a.name, b.name);
	if (s != 0) {
		return s < 0;
	}
	else {
		return a.id < b.id;
	}
}
bool cmp3(R a, R b) {
	if (a.grade != b.grade) {
		return a.grade < b.grade;
	}
	else {
		return a.id < b.id;
	}
}
int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	R *buf = new R[n];
	for (int i = 0; i < n; i++) {
		scanf("%d %s %d", &buf[i].id, &buf[i].name, &buf[i].grade);
	}
	if (c == 1) {
		sort(buf, buf + n, cmp1);
	}
	else if (c == 2) {
		sort(buf, buf + n, cmp2);
	}
	else {
		sort(buf, buf + n, cmp3);
	}
	for (int i = 0; i < n; i++) {
		printf("%06d %s %d\n", buf[i].id, buf[i].name, buf[i].grade);
	}
	return 0;
}