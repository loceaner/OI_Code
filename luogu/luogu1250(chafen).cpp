#include<bits/stdc++.h>
#define il inline
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
using namespace std;
const int N=100005,inf=23333333;
int n,m,to[N],net[N],w[N],dis[N],h[N],cnt;
bool vis[N];
queue<int>q;
il int gi() {
	int a=0;
	char x=getchar();
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')a=(a<<3)+(a<<1)+x-48,x=getchar();
	return a;
}
il void add(int u,int v,int c) {
	to[++cnt]=v,net[cnt]=h[u],h[u]=cnt,w[cnt]=c;
}
int main() {
	n=gi(),m=gi();
	int u,v,c;
	while(m--) {
		u=gi(),v=gi(),c=gi();
		add(u-1,v,c);
	}
	For(i,0,n) {
		if(i!=0)add(i-1,i,0),dis[i]=-inf;
		if(i!=n)add(i,i-1,-1);
	}
	q.push(0);
	while(!q.empty()) {
		int u=q.front();
		vis[u]=0;
		q.pop();
		for(int i=h[u]; i; i=net[i])
			if(dis[to[i]]<dis[u]+w[i]) {
				dis[to[i]]=dis[u]+w[i];
				if(!vis[to[i]])q.push(to[i]),vis[to[i]]=1;
			}
	}
	cout<<dis[n];
	return 0;
}
