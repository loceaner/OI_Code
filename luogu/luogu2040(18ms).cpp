#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main();
int i,j,ans=10005,a[4][4],dx[4]= {0,1,0,-1},dy[4]= {1,0,-1,0}; //四个方向
bool judge(void) { //判断是否全开
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			if(!a[i][j]) return false;
	return true;
}
void change(int x,int y) { //改变一个点及其周围点的状态
	a[x][y]^=1;
	for(int i=0; i<4; i++) {
		int xx=x+dx[i],yy=y+dy[i];
		a[xx][yy]^=1;
	}
}
void search(int x,int y,int tot) {
	if(judge()) ans=min(ans,tot);//更新答案
	if(y>3) { //下一行
		search(x+1,1,tot);
		return;
	}
	if(x>3) return ;//搜索结束
	change(x,y);//改变当前点的状态
	search(x,y+1,tot+1);//答案+1，下一个点
	change(x,y);//回溯
	search(x,y+1,tot);//不改变这个点的状态
}
int main() {
	for(i=1; i<=3; i++)
		for(j=1; j<=3; j++)
			scanf("%d",&a[i][j]);
	search(1,1,0);//从1，1点开始搜索
	printf("%d",ans);
	return 0;
}
