#include<bits/stdc++.h>
using namespace std;

int pre[10101],e[10101];
int num[10101];
int n,m;

int find(int x) {
	if(pre[x]!=x)pre[x]=find(pre[x]);
	return pre[x];
}

void hebing(int x,int y) {
	x=find(x);
	y=find(y);
	if(x==y)return;
	pre[y]=x;
	return;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		pre[i]=i;
	}
	int p;
	int x,y;
	for(int i=1; i<=m; i++) {
		cin>>p;
		scanf("%d%d",&x,&y);
		if(p==0)hebing(x,y);
		else {
			if(e[x]==0)e[x]=find(y);
			else hebing(y,e[x]);
			if(e[y]==0)e[y]=find(x);
			else hebing(x,e[y]);
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		num[find(i)]++;
	}
	for(int i=1; i<=n; i++) {
		if(num[i])ans++;
	}
	printf("%d",ans);
	return 0;
}
