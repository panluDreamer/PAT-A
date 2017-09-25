#include<cstdio>
#include<cstdlib>
struct fraction {
	long long up;
	long long down;
};
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else return gcd(b, a%b);
}
fraction reduction(fraction res) {
	fraction temp = res;
	if (temp.down < 0) {
		temp.down = -temp.down;
		temp.up = -temp.up;
	}
	else if (temp.up == 0) {
		temp.down = 1;
	}
	else {
		int d;
		if (abs(temp.up) >= abs(temp.down)) {
			d = gcd(abs(temp.up), abs(temp.down));
		}
		else {
			d = gcd(abs(temp.down), abs(temp.up));
		}
		temp.up /= d;
		temp.down /= d;
	}
	return temp;
}
int main() {
	int n;
	scanf("%d", &n);
	/*if (n==2) {//3∫≈≤‚ ‘µ„n=2
		while (true);
		return 0;
	}*/
	fraction a, b, c, ans;
	scanf("%lld/%lld", &a.up, &a.down);
	c = a;
	for (int i = 0; i < n - 1; i++) {
		scanf("%lld/%lld", &b.up, &b.down);
		c.up = a.up*b.down + b.up*a.down;
		c.down = a.down*b.down;
		a = reduction(c);
		//buf[i] = a;
	}
	//	printf("%lld/%lld", c.up, c.down);
	ans = reduction(c);
	if (ans.down == 1) {
		printf("%lld", ans.up);
	}
	else if (ans.up == 0) {
		printf("0");
	}
	else if (abs(ans.up) > ans.down) {
		printf("%lld %lld/%lld", ans.up / ans.down, abs(ans.up) % ans.down, ans.down);
	}
	else {
		printf("%lld/%lld", ans.up, ans.down);
	}
}