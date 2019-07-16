#include<bits/stdc++.h>
using namespace std;

inline int read() {
	int ret=0,ff=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*ff;
}

int a[1000],f[1000][1000],min_dp[1000][1000];
signed main() {
	int n,maxn,minn;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		a[n+i]=a[i];
	}
	for(int i=1; i<=2*n; i++)a[i]=a[i]+a[i-1];
	for(int r=2; r<=n; r++) {
		for(int i=1; i<=2*n-r+1; i++) {
			int j=i+r-1;
			f[i][j]=f[i+1][j]+a[j]-a[i-1];
			min_dp[i][j]=min_dp[i+1][j]+a[j]-a[i-1];
			for(int k=i; k<j; k++) {
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[j]-a[i-1]);
				min_dp[i][j]=min(min_dp[i][j],min_dp[i][k]+min_dp[k+1][j]+a[j]-a[i-1]);
			}
		}
	}
	maxn=f[1][n],minn=min_dp[1][n];
	for(int i=2; i<=n; i++) {
		if(f[i][i+n-1]>maxn)maxn=f[i][i+n-1];
		if(min_dp[i][i+n-1]<minn)minn=min_dp[i][i+n-1];
	}
	printf("%d\n%d",minn,maxn);
	return 0;
}
