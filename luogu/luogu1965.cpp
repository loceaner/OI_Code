#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000001
using namespace std;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int n,m,k,x,a[N];
int ans;
long long b;
int pown(int a,int b) {
	int c=1;
	int m=10;
	while (k > 0) {
		if(k&1)
			c=(c*m)%n;
		k=k>>1;
		m=(m*m)%n;
	}
	return c;
}
int main() {
	n=read(),m=read(),k=read(),x=read();
	b=pown(10,k);
	ans=(x%n+b*m)%n;
	printf("%d",ans);
	return 0;
}
