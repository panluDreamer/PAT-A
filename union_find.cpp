#include<iostream>
#include<string>
using namespace std;
int main() {
	string a;
	int num;
	cin >> num;
	getchar();//���ջ��з�
	getline(cin, a);
	cout << "num = " << num << endl;
	cout << "size = " << a.length() << endl;
	cout << a << endl;

}