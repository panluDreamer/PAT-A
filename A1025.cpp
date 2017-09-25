#include<iostream>//scanf string
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct student {
	string id;
	int score;
	int local_rank;
	int final_rank;
	int location;
};
vector<student> buf;
vector<student> temp_buf;
bool cmp(student &a, student &b) {
	if (a.score != b.score) {
		return a.score > b.score;
	}
	else {
		return a.id < b.id;
	}
}
int main() {
	int n, k;
	cin >> n;
	student temp;
	for (int i = 1; i <= n; i++) {
		temp_buf.clear();
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> temp.id >> temp.score;
			temp.location = i;
			temp_buf.push_back(temp);
		}
		sort(temp_buf.begin(), temp_buf.end(), cmp);
		int rank = 1;
		temp_buf[0].local_rank = 1;
		buf.push_back(temp_buf[0]);
		for (int u = 1; u < k; u++) {
			if (temp_buf[u].score != temp_buf[u - 1].score) {
				rank = u + 1;
			}
			temp_buf[u].local_rank = rank;
			buf.push_back(temp_buf[u]);
		}
	}
	sort(buf.begin(), buf.end(), cmp);
	int size = buf.size();
	buf[0].final_rank = 1;
	for (int i = 1; i < size; i++) {
		if (buf[i].score == buf[i - 1].score) {
			buf[i].final_rank = buf[i - 1].final_rank;
		}
		else {
			buf[i].final_rank = i + 1;
		}
	}
	cout << size << endl;
	for (int i = 0; i < size; i++) {
		cout << buf[i].id << " " << buf[i].final_rank << " "
			<< buf[i].location << " " << buf[i].local_rank << endl;
	}
}