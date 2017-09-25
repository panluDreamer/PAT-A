#include<cstdio>
int main() {
	int ag, as, ak;
	int bg, bs, bk;
	int rg, rs, rk;
	scanf("%d.%d.%d", &ag, &as, &ak);
	scanf("%d.%d.%d", &bg, &bs, &bk);
	rk = (ak + bk) % 29;
	as += (ak + bk) / 29;
	rs = (as + bs) % 17;
	ag += (as + bs) / 17;
	rg = ag + bg;
	printf("%d.%d.%d", rg, rs, rk);
	return 0;
}