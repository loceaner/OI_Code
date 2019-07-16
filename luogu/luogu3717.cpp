#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,m,r,f[5001][5001],ans;
int check(int x,int r) {
	return (int)sqrt((double)(r*r-x*x));
}
int main() {
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1; i<=m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=0; j<=r; j++) {
			int k=check(j,r);
			int x1=min(x+k,n);
			int y1=min(y+j,n);
			int x2=max(x-k,1);
			int y2=max(y-j,1);
			f[y1][x2]+=1;
			f[y1][x1+1]-=1;
			if(j!=0) {
				f[y2][x2]+=1;
				f[y2][x1+1]-=1;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			f[i][j]+=f[i][j-1];
			if(!f[i][j])
				ans++;
		}
	}
	printf("%d",n*n-ans);
	return 0;
}
