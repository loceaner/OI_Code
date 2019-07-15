#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 20
using namespace std;
int n,m,t,ans,s[N][N],vis[N][N];
int xx[9]= {0,0,0,1,1,1,-1,-1,-1};
int yy[9]= {1,0,-1,1,0,-1,1,0,-1};
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void dfs(int x,int y,int sum) {
	if(y>m) {
		x++;
		y=1;
	}
	if(x>n) {
		ans=max(ans,sum);
		return ;
	}
	if(vis[x][y]==0) {
		for(int k=0; k<=8; k++)
			vis[x+xx[k]][y+yy[k]]++;
		dfs(x,y+2,sum+s[x][y]);
		for(int k=0; k<=8; k++)
			vis[x+xx[k]][y+yy[k]]--;
	}
	dfs(x,y+1,sum);
}
int main() {
	t=read();
	while(t--) {
		n=read(),m=read();
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				s[i][j]=read();
		memset(vis,0,sizeof(vis));
		ans=0;
		dfs(1,1,0);
		printf("%d\n",ans);
	}
	return 0;
}
