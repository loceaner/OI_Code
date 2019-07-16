#include<iostream>
#include<cstdio>
int main() {
	int f,i,n,t=0,num=0;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&f);
		if(f==0) t++;
		else num++;
	}
	if(t==0) {
		printf("-1");
		return 0;
	}
	if(num<9) {
		printf("0");
		return 0;
	}
	num=num-(num%9);
	for(i=1; i<=num; i++)
		printf("%d",5);
	for(i=1; i<=t; i++)
		printf("%d",0);
	return 0;
}
