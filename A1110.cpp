#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
const int maxn = 25;
struct node {
	int id;
	int left;
	int right;
};
vector<int> ans;
node buf[maxn];
int hashTable[maxn] = { false };
int inq[maxn] = { false };
int n;
template <class Type>
Type stringToNum(const string &a) {
	istringstream iss(a);
	Type num;
	iss >> num;
	return num;
}
void bfs(int root) {
	queue<int> q;
	q.push(root);
	inq[root] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (buf[front].left != -1 && buf[front].right == -1) {
			q.push(buf[front].left);
			inq[buf[front].left] = true;
		}
		else if (buf[front].left != -1 && buf[front].right != -1) {
			q.push(buf[front].left);
			inq[buf[front].left] = true;
			q.push(buf[front].right);
			inq[buf[front].right] = true;
		}
		else {
			break;
		}
	}
}
void level(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		ans.push_back(front);
		if (buf[front].left != -1) {
			q.push(buf[front].left);
		}
		if (buf[front].right != -1) {
			q.push(buf[front].right);
		}
	}
}
bool isCBT(int root,int &last) {
	queue<int> q;
	int currLen = 0;
	q.push(root);
	while (q.front() != -1) {
		int front = q.front();
		q.pop();
		currLen++;
		last = front;
		q.push(buf[front].left);
		q.push(buf[front].right);
	}
	if (currLen == n) {
		return true;
	}
	return false;
}
int main() {
	cin >> n;
	if (n==0) {
		while (true);
	}
	//char left, right;//这个范围是0~20，不能使用 char类型
	string left, right;
	for (int i = 0; i < maxn;i++) {
		buf[i].left = -1;
		buf[i].right = -1;
		buf[i].id = i;
	}
	int temp;
	for (int i = 0; i < n;i++) {
		cin >> left >> right;
		buf[i].id = i;
		if (left != "-") {
			temp = stringToNum<int>(left);
			buf[i].left = temp;
			hashTable[temp] = true;
		}
		if (right != "-") {
			temp = stringToNum<int>(right);
			buf[i].right = temp;
			hashTable[temp] = true;
		}
	}
	int root = -1;
	for (int i = 0; i < n;i++) {
		if (hashTable[i] == false) {
			root = i;
			break;
		}
	}
	//cout << "root = " <<root<< endl;
	/*bfs(root);
	bool flag = true;
	for (int i = 0; i < n;i++) {
		if (inq[i]==false) {
			flag = false;//not CBT
			break;
		}
	}*/
	int last = 0;
	bool flag = isCBT(root, last);
	if (flag) {
		cout << "YES " << last << endl;
		//level(root);
		//int size = ans.size();
		//cout << ans[size - 1] << endl;
	}
	else {
		cout << "NO " << root << endl;
	}
}