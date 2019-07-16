#include<cstdio>
#include<iostream>
using namespace std;
int E[20][20];
int main() {
	int n,ans=0;
	scanf("%d",&n);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			scanf("%d",&E[i][j]);
	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				E[i][j]=min(E[i][j],E[i][k]+E[k][j]);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			ans=max(ans,E[i][j]);
	printf("%d",ans);
	return 0;
}
