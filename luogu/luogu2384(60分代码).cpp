#include<bits/stdc++.h>
using namespace std;
long long dis[1010][1010];
long long n,m,a,b,s;

int qread()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main() {
	n=qread();m=qread();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			dis[i][j]=0xffffff;
		}
	}
	for(int i=1; i<=m; ++i) {
		a=qread();b=qread();s=qread();
		dis[a][b]=s;
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			if(i!=k && dis[i][k]!=0xffffff) {
				for(int j=1; j<=n; j++) {
					if(i!=j&&j!=k&&dis[i][j]>dis[i][k]*dis[k][j]&&dis[i][k]!=0&&dis[k][j]!=0) {
						dis[i][j]=dis[i][k]*dis[k][j];
					}
				}
			}
	printf("%lld",dis[1][n]%9987);
	return 0;
}
