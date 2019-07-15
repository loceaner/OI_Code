#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
#define DB double
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void put(int x) {
	if(x<0) {
		x=-x;
		putchar('-');
	}
	if(x>9)
		put(x/10);
	putchar(x%10+'0');
}
int n;
int m;
struct node {
	int to;
	int dis;
	int nxt;
} edge[200];
int head[60];
int cnt;
bool vis[60];
int ans;
inline void add(int from,int to,int dis) {
	cnt++;
	edge[cnt].to=to;
	edge[cnt].dis=dis;
	edge[cnt].nxt=head[from];
	head[from]=cnt;
}
inline void dfs(int now,int dis) {
	ans=max(ans,dis);
	for(int i=head[now]; i; i=edge[i].nxt) {
		int go=edge[i].to;
		if(!vis[go]) {
			vis[go]=true;
			dfs(go,dis+edge[i].dis);
			vis[go]=false;
		}
	}
}
int main() {
	n=read();
	m=read();
	for(int a,b,c,i=1; i<=m; i++) {
		a=read();
		b=read();
		c=read();
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1; i<=n; i++) {
		vis[i]=true;
		dfs(i,0);
		vis[i]=false;
	}
	put(ans);
	return 0;
}
