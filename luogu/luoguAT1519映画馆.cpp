#include<cstdio>
unsigned long long n,sjp,a,b,i;
unsigned long long max(unsigned long long x,unsigned long long y) {
	if(x>y)
		return x;
	else
		return y;
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&b);
		sjp+=b;
		a=max(a,b);
	}
	printf("%lld\n",n+sjp+a);
}
