#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
using namespace std;
struct node {
	int num;
	char op;
	bool flag;//true: num,false:op
};
vector<node> q;//后缀表达式
stack<char> st;
vector<node> middle;
map<char, int> mp;
bool check(char ch) {
	if (ch >= '0'&&ch <= '9') {
		return true;//one of num
	}
	return false;
}
void change() {
	int s = middle.size();
	node temp;
	for (int i = 0; i < s; i++) {
		if (middle[i].flag) {
			q.push_back(middle[i]);
		}
		else {
			int ch = middle[i].op;
			if (st.empty() == true || ch == '(') {
				st.push(ch);
			}
			else if (ch == ')') {
				while (!st.empty() && st.top() != '(') {
					temp.flag = false;
					temp.num = -1;
					temp.op = st.top();
					q.push_back(temp);
					st.pop();
				}
				if (!st.empty()) {
					st.pop();
				}
			}
			else {
				if (!st.empty()) {
					if (st.top() == '(') {
						st.push(ch);
					}
					else {

						int top = mp[st.top()];
						if (mp[ch] > top) {
							st.push(ch);
						}

						else {
							while (!st.empty() && mp[st.top()] >= mp[ch]) {
								if (st.top() == '(') break;
								temp.flag = false;
								temp.num = -1;
								temp.op = st.top();
								q.push_back(temp);
								st.pop();
							}
							st.push(ch);
						}
					}
				}
			}
		}
	}
	while (!st.empty()) {
		temp.flag = false;
		temp.num = -1;
		temp.op = st.top();
		q.push_back(temp);
		st.pop();
	}
}
double cal() {
	double ans;
	stack<double> data_stack;
	int s = q.size();
	for (int i = 0; i < s; i++) {
		if (q[i].flag == true) {
			data_stack.push(q[i].num);
		}
		else {
			char op = q[i].op;
			double second = data_stack.top();
			data_stack.pop();
			double first = data_stack.top();
			data_stack.pop();
			double temp;
			switch (op)
			{
			case '+': {
				temp = first + second;
				data_stack.push(temp);
				break;
			}
			case '-': {
				temp = first - second;
				data_stack.push(temp);
				break;
			}
			case '*': {
				temp = first * second;
				data_stack.push(temp);
				break;
			}
			case '/': {
				temp = first / second;
				data_stack.push(temp);
				break;
			}
			}
		}
	}
	return data_stack.top();
}
int main() {
	string str;
	mp['+'] = 1;
	mp['-'] = 1;
	mp['*'] = 2;
	mp['/'] = 2;
	mp['('] = 0;
	cin >> str;
	int size = str.length();
	int i = 0;
	int temp_num = 0;
	char temp_op;
	node temp_node;
	while (i < size) {
		if (check(str[i]) == true) {//0~9
			temp_num = temp_num * 10 + (str[i] - '0');
		}
		else {
			if (temp_num != 0) {
				temp_node.num = temp_num;
				temp_num = 0;
				temp_node.flag = true;
				temp_node.op = 'n';
				middle.push_back(temp_node);
			}
			temp_node.flag = false;
			temp_node.op = str[i];
			temp_node.num = -1;
			middle.push_back(temp_node);
		}
		i++;
	}
	if (temp_num != 0) {
		temp_node.num = temp_num;
		temp_num = 0;
		temp_node.flag = true;
		temp_node.op = 'n';
		middle.push_back(temp_node);
	}
	/*int len = middle.size();
	for (int i = 0; i < len; i++) {
		if (middle[i].flag) {
			cout << middle[i].num << " ";
		}
		else {
			cout << middle[i].op << " ";
		}
	}
	cout << endl;*/
	change();
	/*int s = q.size();
	for (int i = 0; i < s; i++) {
		if (q[i].flag) {
			cout << q[i].num << " ";
		}
		else {
			cout << q[i].op << " ";
		}
	}
	cout << endl;*/
	double ans;
	ans = cal();
	cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
}