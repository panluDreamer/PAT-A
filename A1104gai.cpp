#include<cstdio>
int main() {
	int n;
	double v, ans = 0;
	scanf("%d", &n);
	//double sum = 0.0, v;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &v);
		ans += 1.0*i*(n + 1 - i)*v;//Ҫ����1.0��תΪdouble����,����i*(n+1-i)�������
		//ans += v*i*(n + 1 - i);//����дҲ��ͨ��
	}
	//cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
	printf("%.2f\n", ans);
	return 0;
}