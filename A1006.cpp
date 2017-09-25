#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct stu {
	char id[20];
	int in;
	int out;
};
vector<stu> buf;
bool cmp1(stu&a, stu&b) {
	return a.in < b.in;
}
bool cmp2(stu&a, stu&b) {
	return a.out > b.out;
}
int main() {
	int m;
	scanf("%d", &m);
	stu temp;
	int inh, inm, ins, outh, outm, outs;
	for (int i = 0; i < m; i++) {
		scanf("%s %d:%d:%d %d:%d:%d", &temp.id, &inh, &inm, &ins, &outh, &outm, &outs);
		temp.in = inh * 3600 + inm * 60 + ins;
		temp.out = outh * 3600 + outm * 60 + outs;
		buf.push_back(temp);
	}
	sort(buf.begin(), buf.end(), cmp1);
	printf("%s ", buf[0].id);
	sort(buf.begin(), buf.end(), cmp2);
	printf("%s\n", buf[0].id);
}