//#include<iostream>//ʹ��cin,cout��һ�����Ե�ᳬʱ
#include<cstdio>
using namespace std;
struct Node {
	char c;
	int next;
	bool flag;
};
Node buf[100005];
int main() {
	int s1, s2, num;
	int ad, next;
	char data;
	scanf("%d %d %d", &s1, &s2, &num);
//	if (num==2) {
	//	while (true);
	//}
	//cin >> s1 >> s2 >> num;
	//cout << "num = " << num << endl;
	for (int i = 0; i < num;i++) {
	//	cin >> ad >> data >> next;
		scanf("%d %c %d", &ad, &data, &next);
		buf[ad].c = data;
		buf[ad].next = next;
		buf[ad].flag = false;
		//cout << "i = " << i << endl;
	}
	//cout << "here" << endl;
	int index = s1;
	while (index != -1) {
		//cout << buf[index].c;
		buf[index].flag = true;
		index = buf[index].next;
	}
	index = s2;
	int ans;
	while (index != -1) {
	//	cout << buf[index].c;
		if (buf[index].flag) {
			ans = index;
			break;
		}
		index = buf[index].next;
	}
	if (index!=-1) {
		//cout << ans;
		printf("%05d", ans);//ʹ��%05d��ʽ���������5Ϊ�ĸ�λ�����0
	}
	else {
		//cout << "-1";
		printf("-1");
	}
	return 0;
}