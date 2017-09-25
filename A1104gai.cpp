#include<cstdio>
int main() {
	int n;
	double v, ans = 0;
	scanf("%d", &n);
	//double sum = 0.0, v;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &v);
		ans += 1.0*i*(n + 1 - i)*v;//要乘上1.0，转为double类型,否则i*(n+1-i)可能溢出
		//ans += v*i*(n + 1 - i);//这样写也能通过
	}
	//cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
	printf("%.2f\n", ans);
	return 0;
}