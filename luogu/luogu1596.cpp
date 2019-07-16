#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;

int n,m;
char a[101][101];
bool f[101][101]= {false};

int baosou(int x,int y) {//将访问的这个水坑删除
	if(a[x][y+1]=='W') {
		a[x][y+1]='.';
		baosou(x,y+1);
	}
	if(a[x][y-1]=='W'){
		a[x][y-1]='.';
		baosou(x,y-1);
	}
	if(a[x+1][y]=='W') {
		a[x+1][y]='.';
		baosou(x+1,y);
	}
	if(a[x-1][y]=='W') {
		a[x-1][y]='.';
		baosou(x-1,y);
	}
	if(a[x+1][y+1]=='W') {
		a[x+1][y+1]='.';
		baosou(x+1,y+1);
	}
	if(a[x+1][y-1]=='W') {
		a[x+1][y-1]='.';
		baosou(x+1,y-1);
	}
	if(a[x-1][y+1]=='W') {
		a[x-1][y+1]='.';
		baosou(x-1,y+1);
	}
	if(a[x-1][y-1]=='W') {
		a[x-1][y-1]='.';
		baosou(x-1,y-1);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	if(m==0)return 0;
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
            //听我的，永远不要用scanf输入字符
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]=='W') {
				a[i][j]='.';
				ans++;//找到之后将这个点
				baosou(i,j);//开始暴搜
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
