#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int p_coupon[maxn];//positive coupon
int n_coupon[maxn];
int p_product[maxn];
int n_product[maxn];//negative product
bool cmp1(int a, int b) {
	return a > b;
}
bool cmp2(int a,int b) {
	return a < b;
}
int main() {
	int nc, np;
	cin >> nc;
	int p_index = 0, n_index = 0;
	int p_cou_num, n_cou_num, p_pro_num, n_pro_num;
	int temp;
	for (int i = 0; i < nc;i++) {
		cin >> temp;
		if (temp >= 0) {
			p_coupon[p_index++] = temp;
		}
		else {
			n_coupon[n_index++] = temp;
		}
	}
	p_cou_num = p_index;
	n_cou_num = n_index;
	p_index = 0;
	n_index = 0;
	cin >> np;
	for (int i = 0; i < np;i++) {
		cin >> temp;
		if (temp >= 0) {
			p_product[p_index++] = temp;
		}
		else {
			n_product[n_index++] = temp;
		}
	}
	p_pro_num = p_index;
	n_pro_num = n_index;
	sort(p_coupon, p_coupon+p_cou_num, cmp1);
	sort(p_product, p_product + p_pro_num, cmp1);
	sort(n_coupon, n_coupon + n_cou_num, cmp2);
	sort(n_product, n_product + n_pro_num, cmp2);
	int ans = 0;
	int i = 0, j = 0;
	while (i < p_cou_num&&j < p_pro_num) {
		ans += p_coupon[i] * p_product[j];
		i++;
		j++;
	}
	i = 0; 
	j = 0;
	while (i < n_cou_num&&j < n_pro_num) {
		ans += n_coupon[i] * n_product[j];
		i++;
		j++;
	}
	cout << ans << endl;
}