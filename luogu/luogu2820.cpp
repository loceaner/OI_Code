#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define maxn 1010
using namespace std;

int n,m;
long long sum=0;//储存最小生成树权值之和
long long ans=0;//this is answer
int g[maxn][maxn], minn[maxn];
//g数组是用邻接矩阵存储，minn数组存储最小权值
bool u[maxn];//判断是否已加入最小生成树

int main() {
	//我已经不敢用memset赋值二维数组了，太玄学了
	memset(g,0x7f,sizeof(g));
	memset(minn,0x7f,sizeof(minn));//初始为最大值
	memset(u,true,sizeof(u));//初始化全为蓝点
	//前面的都是初始化qwq
	minn[1]=0;//我们从第一个点开始，所以自己到自己的距离为0
	scanf("%d%d",&n,&m);
	int x,y,w;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&w);
		g[x][y]=g[y][x]=w;
		//表示x和y两点之间有一条权值为w的边
		ans+=w;//早早准备好输出嘿嘿
	}
	//Prim算法
	for(int i=1; i<=n; i++) {
		int k=0;
		for(int j=1; j<=n; j++) {
			if(u[j] && minn[k]>minn[j]) {
				k=j;
			}
		}
		u[k]=false;//进入了最小生成树就变为白点
		for(int j=1; j<=n; j++) {
			if(u[j] && minn[j]>g[k][j]) {
				minn[j]=g[k][j];
			}
		}
	}
	for(int i=1; i<=n; i++) {
		sum+=minn[i];
	}
	ans-=sum;//求答案
	cout<<ans<<'\n';
	return 0;
}
