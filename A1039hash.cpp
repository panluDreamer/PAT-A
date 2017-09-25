#include<cstdio>
#include<iostream>
#include<set>
#include<string>
using namespace std;
//const int maxn = 26 * 26 * 26*10 + 100;
const int maxn = 180000;
set<int> student[maxn];
int nameToId(char s[]) {//×Ö·û´®hash
	int id = 0;
	for (int i = 0; i < 3;i++) {
		id = id * 26 + (s[i] - 'A');
	}
	id = id * 10 + (s[3]- '0');
	return id;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	char name[5];
	int id, course_id,num;
	for (int i = 0; i < k;i++) {
		scanf("%d%d", &course_id, &num);
		for (int j = 0; j < num;j++) {
			scanf("%s", &name);
			id = nameToId(name);
			student[id].insert(course_id);
		}
	}
	int size;
	set<int>::iterator it;
	for (int i = 0; i < n;i++) {
		scanf("%s", &name);
		id = nameToId(name);
		printf("%s ", name);
		size = student[id].size();
		printf("%d", size);
		for (it = student[id].begin(); it != student[id].end();it++) {
			printf(" %d", *it);
		}
		printf("\n");
	}
}