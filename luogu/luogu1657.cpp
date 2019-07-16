#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define N 1000
using namespace std;

bool vis[N];
int n,x,y,ans,a[N][N];
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void dfs(int x) {
	if(x==n+1) {
		ans++;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!a[x][i]||vis[i]) continue;
		vis[i]=true;
		dfs(x+1);
		vis[i]=false;
	}
}

int main() {
	n=read();
	if(n==0) {
		printf("0");
		return 0;
	}
	for(int i=1; i<=n; i++) {
		x=read(),y=read();
		a[i][x]=true,a[i][y]=true;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
