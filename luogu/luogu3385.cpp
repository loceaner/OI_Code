#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int head[20005],nxt[100010],ver[100010],edge[100010],tot;

void add(int x,int y,int z) {
	ver[++tot]=y;
	edge[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}

bool vis[20005];
int rd[20005],dis[20005];

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) {
		memset(head,0,sizeof(head));
		tot=0;
		memset(rd,0,sizeof(rd));
		memset(vis,0,sizeof(vis));
		memset(dis,inf,sizeof(dis));
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=m; i++) {
			int a,b,c;
			cin>>a>>b>>c;
			add(a,b,c);
			if(c>=0)add(b,a,c);
		}
		queue<int>q;
		q.push(1);
		vis[1]=1;
		rd[1]=1;
		dis[1]=0;
		int flag=0;
		while(!q.empty()) {
			int now=q.front();
			q.pop();
			vis[now]=0;
			if(flag) {
				break;
			}
			for(int i=head[now]; i; i=nxt[i]) {
				int v=ver[i],val=edge[i];
				if(dis[v]>dis[now]+val) {
					dis[v]=dis[now]+val;
					if(!vis[v]) {
						q.push(v);
						vis[v]=1;
						rd[v]=rd[now]+1;
						if(rd[v]>n) {
							flag=1;
							break;
						}
					}
				}
			}
		}
		if(flag)cout<<"YE5"<<endl;
		else cout<<"N0"<<endl;
	}
	return 0;
}
