#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int t,x,y;
int vis[500000];
struct nond {
	int pos,step;
};
queue<nond>que;
void bfs(int x) {
	while(!que.empty())    que.pop();
	nond tmp;
	tmp.pos=x;
	tmp.step=0;
	vis[x]=1;
	que.push(tmp);
	while(!que.empty()) {
		nond now=que.front();
		que.pop();
		nond a,b,c;
		c.pos=now.pos+1;
		c.step=now.step+1;
		if(c.pos<200000&&!vis[c.pos])    que.push(c),vis[c.pos]=1;
		if(c.pos==y) {
			cout<<c.step<<endl;
			break;
		}
		a.pos=now.pos-1;
		a.step=now.step+1;
		if(a.pos<200000&&!vis[a.pos])    que.push(a),vis[a.pos]=1;
		if(a.pos==y) {
			cout<<a.step<<endl;
			break;
		}
		b.pos=now.pos*2;
		b.step=now.step+1;
		if(b.pos<200000&&!vis[b.pos])    que.push(b),vis[b.pos]=1;
		if(b.pos==y) {
			cout<<b.step<<endl;
			break;
		}
	}
}
int main() {
	scanf("%d",&t);
	while(t--) {
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&x,&y);
		bfs(x);
	}
}
