#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 110;
int insertSort[maxn][maxn];
int mergeSort[maxn][maxn];
int n;
int buf[maxn] = { 0 };
int mergeBuf[maxn] = { 0 };
int merge_temp[maxn] = { 0 };
int a[maxn] = { 0 };
bool cmp(int a, int b) {
	return a < b;
}
bool cmp_array(int a[], int b[]) {
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			flag = false;
			break;
		}
	}
	return flag;
}
void insert_sort() {//中间序列不包括初始序列,i=2
	int index = 0;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		index = 0;
		sort(buf, buf + i, cmp);
		for (int j = 0; j < n; j++) {
			insertSort[i][index++] = buf[j];
		}
	}
}
void merge_array(int start,int mid,int end) {
	fill(merge_temp, merge_temp + maxn, 0);
//	cout << "before array:" << endl;
	//for (int i = 0; i < n; i++) {
	//	cout << mergeBuf[i] << " ";
	//}
	//cout << endl;
	int i = start, j = mid + 1;
	int index = start;
	while (i <= mid&&j <= end) {
		if (mergeBuf[i] < mergeBuf[j]) {
			merge_temp[index++] = mergeBuf[i];
			i++;
		}
		else {
			merge_temp[index++] = mergeBuf[j];
			j++;
		}
	}
	while (i <= mid) {
		merge_temp[index++] = mergeBuf[i];
		i++;
	}
	while (j <= end) {
		merge_temp[index++] = mergeBuf[j];
		j++;
	}
	for (int k = start; k <= end;k++) {
		mergeBuf[k] = merge_temp[k];
	}
	


}
/*void merge_sort(int start,int end) {
	cout << "start = " << start << " end = " << end << endl;
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge_array(start, mid, end);
		cout << "after array:" << endl;
		for (int i = 0; i < n; i++) {
			cout << mergeBuf[i] << " ";
		}
		cout << endl;
	}
}*/
void merge_sort() {
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2) {
		if (step!=2&&cmp_array(mergeBuf,a)) {
			flag = true;//中间序列与给定序列相同
		}
		for (int i = 0; i < n; i += step) {
			sort(mergeBuf + i, mergeBuf + min(i + step, n));
		}
		if (flag) {
			for (int i = 0; i < n;i++) {
				cout << mergeBuf[i];
				if (i != n - 1) {
					cout << " ";
				}
			}
			return;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
		mergeBuf[i] = buf[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	insert_sort();
	int ans_insert = -1;
	for (int i = 2; i <= n; i++) {//从i=2开始
		if (cmp_array(a, insertSort[i])) {
			ans_insert = i;
			break;
		}
	}
	if (ans_insert != -1) {
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < n; i++) {
			cout << insertSort[ans_insert + 1][i];
			if (i != n - 1) {
				cout << " ";
			}
		}
	}
	else {
		cout << "Merge Sort" << endl;
		//merge_sort(0, n - 1);
		merge_sort();
	}
}