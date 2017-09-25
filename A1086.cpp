#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
vector<int> preOrder;
vector<int> inOrder;
vector<int> postOrder;
stack<int> st;
const int maxn = 40;
int index = 0;
struct node {
	int data;
	node *left;
	node *right;
};
template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

node* createTree(int preL, int preR, int inL, int inR) {
	if (preL>preR) {
		return NULL;
	}
	node *root = new node();
	root->data = preOrder[preL];
	//cout << "root" << root << endl;
	int k;
	for (int i = inL; i <= inR;i++) {
		if (inOrder[i] == preOrder[preL]) {
			k = i;
			break;
		}
	}
	int numLeft = k - inL;
	root->left = createTree(preL + 1, preL + numLeft, inL, k - 1);
	root->right = createTree(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
void post_order(node* root) {
	if (root == NULL) {
		return;
	}
	post_order(root->left);
	post_order(root->right);
	postOrder.push_back(root->data);
}
int main() {
	int n;
	string a;
	cin >> n;
	getchar();
	char temp[50];
	for (int i = 0; i < 2 * n;i++) {
		cin.getline(temp, sizeof(temp));
		a = temp;
		if (a.at(1) == 'u') {//Push
			int x = stringToNum<int>(a.substr(5, 5));
			preOrder.push_back(x);
			st.push(x);
		}
		else {//Pop
			inOrder.push_back(st.top());
			st.pop();
		}
	}
	
	node* root = createTree(0, preOrder.size() - 1, 0, inOrder.size() - 1);
	//cout << "root = " << root <<endl;
	post_order(root);
	//cout << "size = " << postOrder.size() << endl;
	for (int i = 0; i < n;i++) {
		cout << postOrder[i];
		if (i != n-1) {
			cout << " ";
		}
	}
}