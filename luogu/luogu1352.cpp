#include <iostream>
#include <cstdio>
using namespace std;

long long n,m,x,k;

int ksm(int x) {
	if (x==1) return 10;
	long long q=ksm(x/2);
	if (x%2==0)
		return q*q%n;
	else
		return q*q*10%n;
}

int main() {
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	m=m*ksm(k)%n;
	x=(x+m)%n;
	printf("%lld",x);
}
