#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
struct book {
	string id;
	string title;
	string author;
	vector<string> key;
	string publisher;
	string year;
};
book buf[10010];
vector<string> change(string a) {
	vector<string> key;
	int size = a.size();
	string temp;
	for (int i = 0; i < size; i++) {
		if (a.at(i) == ' ') {
			key.push_back(temp);
			temp.clear();
		}
		else {
			temp += a.at(i);
			if (i == size - 1) {
				key.push_back(temp);
				temp.clear();
			}
		}
	}
	return key;
}
int main() {
	int n;
	cin >> n;
	char temp[300];
	string a;
	for (int i = 0; i < n; i++) {
		cin >> buf[i].id;
		getchar();
		cin.getline(temp, sizeof(temp));
		buf[i].title = temp;
		cin.getline(temp, sizeof(temp));
		buf[i].author = temp;
		cin.getline(temp, sizeof(temp));
		a = temp;
		buf[i].key = change(a);
		cin.getline(temp, sizeof(temp));
		buf[i].publisher = temp;
		cin >> buf[i].year;
	}
	int m;
	set<string> ans;
	cin >> m;
	getchar();
	for (int i = 0; i < m; i++) {
		ans.clear();
		cin.getline(temp, sizeof(temp));
		a = temp;
		char num = a.at(0);
		int len = a.length();
		string b = a.substr(3, len - 3);
		cout << a << endl;
		//cout << "b = " << b << endl;
		switch (num)
		{
		case '1': {
			for (int j = 0; j < n; j++) {
				if (buf[j].title == b) {
					ans.insert(buf[j].id);
				}
			}
			break;
		}
		case '2': {
			for (int j = 0; j < n; j++) {
				if (buf[j].author == b) {
					ans.insert(buf[j].id);
				}
			}
			break;
		}
		case '3': {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < buf[j].key.size(); k++) {
					if (buf[j].key.at(k) == b) {
						ans.insert(buf[j].id);
					}
				}
			}
			break;
		}
		case '4': {
			for (int j = 0; j < n; j++) {
				if (buf[j].publisher == b) {
					ans.insert(buf[j].id);
				}
			}
			break;
		}
		case '5': {
			for (int j = 0; j < n; j++) {
				if (buf[j].year == b) {
					ans.insert(buf[j].id);
				}
			}
			break;
		}
		}
		int set_size = ans.size();
		vector<string> out;
		if (set_size == 0) {
			cout << "Not Found" << endl;
		}
		else {
			set<string>::iterator it;
			for (it = ans.begin(); it != ans.end(); it++) {
				cout << *it << endl;
			}
		}
	}
}