#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct R {
	char name[12];
	int age;
	int worth;
};
//void clear(R[], int size);
bool cmp(R a, R b) {
	if (a.worth != b.worth) {
		return a.worth > b.worth;
	}
	else if (a.age != b.age) {
		return a.age < b.age;
	}
	else {
		return strcmp(a.name, b.name) < 0;
	}
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	R *buf = new R[n];
	R *s = new R[n];//在各自年龄中财富值在100名以内的人,(不进行预处理，测试点2会超时)
	int *age = new int[n];//某年龄的人数
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", &buf[i].name, &buf[i].age, &buf[i].worth);
	}
	int index = 0;

	sort(buf, buf + n, cmp);
	for (int j = 0; j < n; j++) {
		if (age[buf[j].age] < 100) {
			age[buf[j].age]++;
			s[index++] = buf[j];
		}
	}
	int m, min, max;
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &m, &min, &max);
		//int flag = false;
		//	for (int j = 0; j < n; j++) {
		//		if (buf[j].age >= min&&buf[j].age <= max) {
		//			flag = true;
			//		s[index++] = buf[j];
					//if (index==110) {
					//	break;
				//	}
			//	}
			//}
		int printNum = 0;
		printf("Case #%d:\n", i);
		for (int j = 0; j < index&&printNum < m; j++) {
			if (s[j].age >= min&&s[j].age <= max) {
				printf("%s %d %d\n", s[j].name, s[j].age, s[j].worth);
				printNum++;
			}
		}
		if (printNum == 0) {
			printf("None\n");
		}
		/*	if (!flag) {
				printf("Case #%d:\n", i);
				printf("None\n");
			}
			else {
			//	sort(s, s + index, cmp);
				printf("Case #%d:\n", i);
				if (m <= index) {
					for (int d = 0; d < m; d++) {
						printf("%s %d %d\n", s[d].name, s[d].age, s[d].worth);
					}
				}
				else {
					for (int d = 0; d < index; d++) {
						printf("%s %d %d\n", s[d].name, s[d].age, s[d].worth);
					}
				}
				clear(s, index);
			}*/
	}
}
/*void clear(R buf[], int size) {
	for (int i = 0; i < size; i++) {
		buf[i].worth = 0;
		buf[i].age = 0;
		strcpy(buf[i].name, "");
	}
}*/