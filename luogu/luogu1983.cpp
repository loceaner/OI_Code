//看到这道题的时候一点思路都没有......
//再读一次题发现也没有思路......
//再读一次终于明白了题目的意思.
//在火车从起点到终点的所有站点中，
//停靠的站点的车站级别一定比不停靠的高,
//设起点为s，终点为t,如果只有一趟火车，
//那么所有停靠的站的等级只需要比不停靠的站的最高值多1即可.
//如果再增加一趟火车，这趟火车在上一趟火车的起始点之内，那么还要再+1,
//如果在起始点之外那么就和一趟火车一样处理,如果有n趟呢......
//可以想到如果拓扑排序.在起始点内不能停靠的站向可以停靠的站连有向边,
//然后找到入度为0的点(没有边指向的点),删除这个点和这个点所连出去的所有路径，
//路径指向的点的入度-1，当所有入度为0的点（撤销原入度为0后入度变为0在第一轮不解决）都解决了之后，
//进行下一轮，进行一轮就累加一下计数器，最后输出结果即可.这是拓扑排序的基本方法，很好理解，
//实在不能理解画个图就能理解了.还有一个问题，为什么要多个点在同一轮进行处理呢?
//可以想到如果按照之前提到的方式建图，那么就会有多个拓扑序列，
//我们可以认为每一次对所有的拓扑序列的操作是等价的，直到没有入度为0的点即可.
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn=1010;
int n,m;
int f[maxn];//flag标记
int top,first,ans=0;//ans答案
int vis[maxn],s,a[maxn],e[maxn][maxn];//邻接矩阵存储
int ru[maxn];//存入度的数组
int s_tack[maxn];//手打栈

//快读qaq
inline int read() {
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-48,c=getchar();
	}
	return x*f;
}

//输入、初始化和初步处理
void init() {
	n=read();
	m=read();
	for(int i=1; i<=m; i++) {
		memset(f,0,sizeof(f));
		s=read();
		for(int j=1; j<=s; j++) {
			a[j]=read();
			f[a[j]]=1;//已标记过
		}
		for(int j=a[1]; j<=a[s]; j++)
			if(!f[j]) //如果没有标记过，将其标记
				for(int k=1; k<=s; k++)
					if(!e[j][a[k]]) { //如果没有值
						e[j][a[k]]=1;//将其值定为1
						ru[a[k]]++;//a[k]这个点的入度加一
					}
	}
}

void topsort() { //拓扑排序
	first=1;
	while(top!=0 || first!=0) {
		first=0,top=0;
		for(int i=1; i<=n; i++) {
			if(!ru[i] && !vis[i]) {
				s_tack[++top]=i;
				//如果这个点的入度为零并且没有访问过就将其入栈并标记为访问过
				vis[i]=1;
				//标记已访问过
			}
		}
		for(int i=1; i<=top; i++) {
			for(int j=1; j<=n; j++) {
				if(e[s_tack[i]][j]!=0) {
					e[s_tack[i]][j]=0;
					ru[j]--;
				}
			}
		}
		ans++;
	}
	ans--;
	//因为当top为零的时候累加器还在累加，所以最后要减去1
	printf("%d",ans);//愉快输出
}

int main() {
	init();
	topsort();
	return 0;
}
