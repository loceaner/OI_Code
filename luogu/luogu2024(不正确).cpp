#include<bits/stdc++.h>
using namespace std;

const int maxn=10101;
int f[maxn],dis[maxn];
int n,m;

int find(int x) {
	if(f[x]!=x) {
		int y=x;
		f[x]=find(f[x]);
		dis[x]=(dis[x]+dis[y])%3;
	}
}

int main() {
	int res=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)f[i]=i,dis[i]=0;
	for(int i=1; i<=m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(b>n || c>n) {
			res++;
			continue;
		}
		if(a==1) {
			if(b==c)continue;
			int u=find(b),v=find(c);
			if(u==v) {
				if(dis[b]!=dis[c])res++;
			} else {
				dis[v]=3-dis[c];
				f[v]=b;
			}
		} else {
			if(b==c) {
				res++;
				continue;
			}
			int u=find(b),v=find(c);
			if(u==v) {
				if((dis[b]-dis[c]+3)%3!=2)res++;
			} else {
				dis[v]=(1-dis[c]+3)%3;
				f[v]=b;
			}
		}
	}
	cout<<res;
	return 0;
}

