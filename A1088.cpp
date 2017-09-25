#include<cstdio>
#include<cstdlib>//包括abs函数，而不是math.h,cmath头文件！！！
using namespace std;
struct fraction {
	long int up;
	long int down;
};
long int gcd(long int a, long int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}
fraction reduction(fraction a) {
	if (a.down < 0) {
		a.up = -a.up;
		a.down = -a.down;
	}
	if (a.up == 0) {
		a.down = 1;
	}
	else {
		int d = gcd(abs(a.up), abs(a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}
fraction add(fraction a, fraction b) {
	fraction res;
	res.up = a.up*b.down + a.down*b.up;
	res.down = a.down*b.down;
	res = reduction(res);
	return res;
}
fraction sub(fraction a, fraction b) {
	fraction res;
	res.up = a.up*b.down - a.down*b.up;
	res.down = a.down*b.down;
	res = reduction(res);
	return res;
}
fraction multi(fraction a, fraction b) {
	fraction res;
	res.up = a.up*b.up;
	res.down = a.down*b.down;
	res = reduction(res);
	return res;
}
fraction divide(fraction a, fraction b) {
	fraction res;
	res.up = a.up*b.down;
	res.down = a.down*b.up;
	res = reduction(res);
	return res;
}
void printFraction(fraction a) {
	if (a.up == 0) {
		printf("0");
	}
	else if (a.down == 1) {
		printf("%ld", a.up);
	}
	else if (abs(a.up) > abs(a.down)) {
		printf("%ld %ld/%ld", a.up / a.down, abs(a.up) % a.down, a.down);
	}
	else {
		printf("%ld/%ld", a.up, a.down);
	}
}
void p(fraction a) {
	if (a.up < 0) {
		printf("(");
		printFraction(a);
		printf(")");
	}
	else {
		printFraction(a);
	}
}
int main() {
	fraction a, b;
	scanf("%ld/%ld %ld/%ld", &a.up, &a.down, &b.up, &b.down);
	a = reduction(a);
	b = reduction(b);
	//printf("a.up=%ld,a.down=%ld,b,up=%ld,b.down=%ld", a.up, a.down, b.up, b.down);
	fraction res;
	res = add(a, b);
	p(a);
	printf(" + ");
	p(b);
	printf(" = ");
	p(res);
	printf("\n");
	res = sub(a, b);
	p(a);
	printf(" - ");
	p(b);
	printf(" = ");
	p(res);
	printf("\n");
	res = multi(a, b);
	p(a);
	printf(" * ");
	p(b);
	printf(" = ");
	p(res);
	printf("\n");
	if (b.up == 0) {
		p(a);
		printf(" / ");
		p(b);
		printf(" = Inf\n");//大小I，而不是小写i
	}
	else {
		res = divide(a, b);
		p(a);
		printf(" / ");
		p(b);
		printf(" = ");
		p(res);
		printf("\n");
	}


}