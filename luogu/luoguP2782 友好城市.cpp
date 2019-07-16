#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 200005
using namespace std;

struct node {
	int x,y;
} a[N];

int n,dp[N],s[N],top;

bool cmp(node a,node b) {
	return a.x<b.x;
}

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++) {
		if(a[i].y>=s[top]) s[++top]=a[i].y;
		else s[lower_bound(s,s+top,a[i].y)-s]=a[i].y;
	}
	printf("%d\n",top);
	return 0;
}
