#include<iostream>
#include<algorithm>
using namespace std;
struct Student {
	char name[15];
	char id[15];
	int grade;
};
bool cmp(Student a,Student b) {
	return a.grade > b.grade;
}
int main() {
	int n;
	cin >> n;
	Student *buf = new Student[n];
	for (int i = 0; i < n;i++) {
		cin >> buf[i].name >> buf[i].id >> buf[i].grade;
	}
	sort(buf, buf + n, cmp);
	int min, max;
	cin >> min >> max;
	int count = 0;
	for (int i = 0; i < n;i++) {
		if (buf[i].grade>=min&&buf[i].grade<=max) {
			cout << buf[i].name << " " << buf[i].id << endl;
			count++;
		}
	}
	if (count==0) {
		cout << "NONE" << endl;
	}
	return 0;
}