#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 10010;
int hashTable[maxn] = { 0 };
bool checked[maxn] = { false };
bool isPrime(int num) {
	if (num == 1) {
		return false;
	}
	else {
		int temp = sqrt(1.0*num);
		for (int i = 2; i <= temp; i++) {
			if (num%i == 0) return false;
		}
		return true;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int id;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &id);
		hashTable[id] = i;
	}
	int k;
	scanf("%d", &k);
	int rank;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &id);
		if (checked[id] == true) {
			printf("%04d: Checked\n", id);
		}
		else {
			rank = hashTable[id];
			//printf("%04d\n", rank);
			if (rank == 0) {
				printf("%04d: Are you kidding?\n", id);
			}
			else if (rank == 1) {
				printf("%04d: Mystery Award\n", id);
				checked[id] = true;
			}
			else if (isPrime(rank)) {
				printf("%04d: Minion\n", id);
				checked[id] = true;
			}
			else {
				printf("%04d: Chocolate\n", id);
				checked[id] = true;
			}

		}
	}
	return 0;
}