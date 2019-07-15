#include <iostream>
#include <cstdio>

using namespace std;

int m,t,num=0,ans;
int f[2500][2500];
int w[2500],v[2500];

int main() {
	scanf("%d%d",&t,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&w[i],&v[i]);
	}
	for(int i=1; i<=m; i++) {
		for(int j=t; j>=0; j--) {
			f[i][j]=f[i-1][j];
			if(j>=w[i]) {
				f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);
			}
		}
	}
	for(int i=1; i<=m; i++)
		for(int j=0; j<=t; j++)
			ans=max(ans,f[i][j]);
	printf("%d",ans);
	return 0;
}
