#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
const int maxn = 110;
int insertSort[maxn][maxn];
int heapSort[maxn][maxn];
int heap[maxn] = { 0 };
priority_queue<int, vector<int>, greater<int>> q;//小顶堆
int n;
int buf[maxn] = { 0 };
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
	for (int i =1; i <= n; i++) {
		index = 0;
		sort(buf, buf + i, cmp);
		for (int j = 0; j < n; j++) {
			insertSort[i][index++] = buf[j];
		}
	}
}
void printArray(int a[]) {
	cout << "array:";
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void downAdjust(int low, int high) {
	int i = low, j = 2 * i;
	while (j <= high) {//存在孩子节点
		if (j + 1 <= high&&heap[j + 1] > heap[j]) {//存在右孩子
			j = j + 1;
		}
		if (heap[i] < heap[j]) {
			swap(heap[i], heap[j]);
			i = j;
			j = 2 * i;
		}
		else {
			break;
		}
	}
}
void createHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downAdjust(i, n);
	}
}
void heap_sort() {
	createHeap();
	int count = 1, index = 0;
	for (int i = n; i > 1; i--) {//n-1次
		swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
		//printArray(heap);
		for (int j = 1; j <= n; j++) {
			heapSort[count][index++] = heap[j];
		}
		index = 0;
		count++;
	}
}
int main() {//
	cin >> n;
	int index = 1;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
		heap[index++] = buf[i];
	}
	//printArray(heap);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	insert_sort();
	int temp[maxn] = { 0 };
	int ans_insert = -1;
	for (int i = 2; i <= n; i++) {//从i=2开始
		bool f = cmp_array(a, insertSort[i]);
		if (f) {
			ans_insert = i;
			break;
		}
	}
	if (ans_insert != -1) {
		cout << "Insertion Sort" << endl;
		for (int j = 0; j < n; j++) {
			cout << insertSort[ans_insert + 1][j];
			if (j != n - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
	else {
		heap_sort();
		int heap_ans = -1;
		//	cout << "heapSort:";
		//	for (int i = 1; i < n;i++) {
	//			for (int j = 0; j < n;j++) {
	//				cout << heapSort[i][j] << " ";
	//			}
		//		cout << endl;
		//	}
		for (int i = 1; i < n; i++) {
			bool f = cmp_array(a, heapSort[i]);
			if (f) {
				heap_ans = i;
				break;
			}
		}
		if (heap_ans != -1) {
			cout << "Heap Sort" << endl;
			for (int j = 0; j < n; j++) {
				cout << heapSort[heap_ans + 1][j];
				if (j != n - 1) {
					cout << " ";
				}
			}
		}
	}
}