#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int pre[maxn];
int x,y;

int find(int x) {
	while(pre[x]!=x) {
		x=pre[x];
	}
	return x;
}

int un(int r1,int r2) {
	pre[r2]=r1;
}

int main() {
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++) {
		pre[i]=i;
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		int r1=find(x);
		int r2=find(y);
		if(r1!=r2)
			un(r1,r2);
	}
	for(int i=1; i<=s; i++) {
		scanf("%d%d",&x,&y);
		if(find(x)==find(y))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
