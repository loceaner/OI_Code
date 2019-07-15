#include<bits/stdc++.h>
using namespace std;
int st[100005],sum=0;
int sjp,zql,ad,d,n,yu,bas,maxx,a,b,c;
int main() {
	scanf("%d",&yu);
	scanf("%d%d",&bas,&b);
	st[bas]=b;
	maxx=bas;
	scanf("%d%d",&a,&b);
	while(a!=-1||b!=-1) {
		st[a]=b;
		if(a>maxx)
			maxx=a;
		scanf("%d%d",&a,&b);
	}
	scanf("%d",&ad);
	if(st[yu]==0) {
		if(yu>maxx) {
			st[yu]=st[maxx]-(yu-maxx)*ad;
			maxx=yu;
		}
		if(yu<maxx) {
			st[yu]=st[maxx]+(maxx-yu)*ad;
		}
	}
	zql=yu+1;
	sjp=yu-1;
	if(st[sjp]==0) {
		st[sjp]=st[yu]+ad;
	}
	if(st[zql]==0) {
		st[zql]=st[yu]-ad;
	}
	int x=st[yu],y=st[sjp],z=st[zql];
	while(true) {
		a=(yu-bas)*x;
		b=(sjp-bas)*y;
		c=(zql-bas)*z;
		if(b>a) {
			sum--;
			yu--;
			sjp--;
			zql--;
		} else if(c>a) {
			sum++;
			yu++;
			sjp++;
			zql++;
		} else if(a>=b&&a>=c) {
			printf("%d",sum);
			return 0;
		}
	}
	return 0;
}
