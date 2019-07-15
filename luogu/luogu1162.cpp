#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<cstring>
#include<list>
#include<set>
#include<map>
#include<cctype>
using namespace std;

int dx[5][3]={{0,0,0},{0,0,1},{0,0,-1},{0,-1,0},{0,1,0}};
int n;
int a[31][31];
int b[31][31];

void dfs(int x,int y){
	if(x<0||x>n+1||y<0||y>n+1||a[x][y]!=0)return;
	a[x][y]=1;
	for(int i=1;i<=4;i++){
		dfs(x+dx[i][1],y+dx[i][2]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
			if(b[i][j]==0)a[i][j]=0;
			else a[i][j]=2;
		}
	}
	dfs(0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0)cout<<2<<" ";
			else cout<<b[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
