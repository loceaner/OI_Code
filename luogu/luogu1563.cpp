#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#define maxn 100000+10
using namespace std;

int n,m,now,x,y;

struct node {
	int to;
	string name;
} a[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i) {
		scanf("%d",&a[i].to );
		cin>>a[i].name ;
	}
	for(int i=1; i<=m; ++i) {
		scanf("%d%d",&x,&y);
		if(x==0&&a[now].to ==0)
			now=(now+n-y)%n;
		else if(x==0&&a[now].to ==1)
			now=(now+y)%n;
		else if(x==1&&a[now].to ==1)
			now=(now+n-y)%n;
		else if(x==1&&a[now].to ==0)
			now=(now+y)%n;
	}
	cout<<a[now].name;
	return 0;
}
