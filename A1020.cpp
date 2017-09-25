#include<iostream>
//使用字符串存储post,in,与题目要求节点数据整数不符，当数字超过9是会出错
#include<string>
#include<queue>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
};
string level_order;
void create(node *&root, string post, string in) {
	if (post.length() == 0) {
		root = NULL;
		return;
	}
	char d = post[post.length() - 1];
	int index = in.find(d);
	string left_in = in.substr(0, index);
	string right_in = in.substr(index + 1);
	string left_post = post.substr(0, left_in.length());
	string right_post = post.substr(left_in.length(), right_in.length());
	root = new node;
	if (root != NULL) {
		root->data = d - '0';
		create(root->left, left_post, left_in);
		create(root->right, right_post, right_in);
	}
}
void in_order(node*root) {
	if (root == NULL) {
		return;
	}
	in_order(root->left);
	in_order(root->right);
	cout << root->data;

}
void level(node *root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node *now = q.front();
		q.pop();
		level_order += now->data + '0';
		//cout << now->data;
		if (now->left != NULL) q.push(now->left);
		if (now->right != NULL) q.push(now->right);
	}
}
int main() {
	int n;
	node *root;
	cin >> n;
	getchar();
	string post, in;
	char temp[40];
	cin.getline(temp, sizeof(temp));
	post = temp;
	cin.getline(temp, sizeof(temp));
	in = temp;
	for (string::iterator itr = post.begin(); itr != post.end(); itr++) {
		if (*itr == ' ') {
			post.erase(itr);
		}
	}
	for (string::iterator itr = in.begin(); itr != in.end(); itr++) {
		if (*itr == ' ') {
			in.erase(itr);
		}
	}
	create(root, post, in);
	level(root);
	cout << level_order[0];
	for (int i = 1; i < level_order.length(); i++) {
		cout << " " << level_order[i];

	}
	//cout << level_order << endl;
    //in_order(root);
   //cout << root->data << endl;
	//cout << post << " " << in << endl;
}