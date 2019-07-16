#include<iostream>
#include<cstdio>
using namespace std;

int n,m,v,w,d[100001];

int main() {
	scanf("%d%d",&m,&n);
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&v,&w);
		for(int j=v; j<=m; j++) {
			d[j]=max(d[j],d[j-v]+w);
		}
	}
	printf("%d",d[m]);
	return 0;
}
