#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int pre[10010];
int n,m;

//Â·¾¶Ñ¹Ëõ£¿£¿
int find(int x) {
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}

int main() {
	int p,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)pre[i]=i;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&p,&x,&y);
		if(p==1) {
			int r1=find(x);
			int r2=find(y);
			if(r1!=r2) {
				pre[r2]=r1;
			}
		} else if(find(x)==find(y))
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
