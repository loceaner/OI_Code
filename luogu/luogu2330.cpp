#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,maxn=-0x7fffffff;
int g[301][301],minn[301];
bool u[301];

int main() {
	memset(g,0x7f,sizeof(g));
	memset(minn,0x7f,sizeof(minn));
	memset(u,true,sizeof(u));
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		g[x][y]=g[y][x]=z;
	}
	minn[1]=0;
	for(int i=1; i<=n; i++) {
		int k=0;
		for(int j=1; j<=n; j++) {
			if(u[j] && minn[j]<minn[k]) {
				k=j;
			}
		}
		u[k]=false;//ǰ��ƪ���Ͷ������������Ĵ���qwq
		maxn=max(maxn,minn[k]);
		//��ǰ�漸ƪ��ͬ�ĵط����������������Ҫ�����������ֵ
		for(int j=1; j<=n; j++) {
			if(u[j] && minn[j]>g[k][j]) {
				minn[j]=g[k][j];
			}
		}
	}
	cout<<n-1<<" "<<maxn<<'\n';
	return 0;
}
