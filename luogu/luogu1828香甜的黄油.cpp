#include<bits/stdc++.h>
using namespace std;

const int INF=99999999;
int n,p,c;
int mapp[1000][1000],d[1000][1000];
int vis[1000]={0};
int ans=INF;

int main() {
	scanf("%d%d%d",&n,&p,&c);
	for(int i=1; i<=p; i++) {
		for(int j=1; j<=p; j++) {
			if(i==j) {
				mapp[i][j]=0;
				d[i][j]=0;
			} else {
				mapp[i][j]=INF;
				d[i][j]=INF;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		int t;
		scanf("%d",&t);
		vis[t]++;
	}
	for(int i=1; i<=c; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		mapp[u][v]=mapp[v][u]=w;
		d[u][v]=d[v][u]=w;
	}
	for(int k=1; k<=p; k++) {
		for(int i=1; i<=p; i++) {
			for(int j=1; j<=i; j++) {
				if(d[i][j]>d[i][k]+d[k][j]) {
					d[i][j]=d[i][k]+d[k][j];
					d[j][i]=d[i][j];
				}
			}
		}
	}
	for(int i=1; i<=p; i++) {
		int maxn=0;
		for(int j=1; j<=p; j++) {
			maxn+=d[i][j]*vis[j];
		}
		if(ans>maxn)ans=maxn;
	}
	cout<<ans;
	return 0;
}
