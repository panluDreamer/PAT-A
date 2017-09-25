#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp1(int a, int b) {
	return a < b;
}
bool cmp2(int a, int b) {
	return a > b;
}
int arr1[4] = { 0 };//注意应该写arr1[4],而不是3，找了好久错误
int arr2[4] = { 0 };
void to_array(int num, int *buf) {
	for (int i = 0; i < 4;i++) {
		buf[i] = 0;//clear,否则num=1出错
	}
	int index = 3;
	while (num != 0) {
		buf[index] = num % 10;
		num /= 10;
		index--;
	}
}
int to_num(int buf[]) {
	return buf[0] * 1000 + buf[1] * 100 + buf[2] * 10 + buf[3];
}
int main() {
	int num;
	scanf("%d", &num);
	//if (num == 1) {//num==1时出错！！！
		//while (true);
	//	printf("1000 - 0001 = 0999\n9991 - 0999 = 8992\n9982 - 2899 = 7083\n8730 - 0378 = 8352\n8532 - 2358 = 6174");
	//	return 0;
	//}
	int temp = num;
	int a = num, b = num;
	while (1) {
		to_array(temp, arr1);
		sort(arr1, arr1 + 4, cmp2);
		a = to_num(arr1);
		to_array(temp, arr2);
		sort(arr2, arr2 + 4, cmp1);
		b = to_num(arr2);
		printf("%04d - %04d = %04d\n", a, b, a - b);
		temp = a - b;
		if (temp == 0 || temp == 6174) {
			break;
		}
	}
}