#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxT=4000105;

int n,m,t,ti,ans=1e9,a[105],cnt[maxT],sum[maxT],f[maxT];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		if(a[i]-a[i-1]>2* m) {
			int t=a[i]-a[i-1]-2*m;
			for(int j=i; j<=n; j++) {
				a[j]-=t;
			}
		}
		t=max(t,a[i]);
	}
	for(int i = 1; i <= n; i++) {
		cnt[a[i]]++;
		sum[a[i]]+=a[i];
	}
	for(int i=1; i<t+m; i++) {
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	for(int i=0; i<t+m; i++) {
		f[i]=cnt[i]*i-sum[i];
		for(int j=max(0,i-2*m); j<=i-m; j++) {
			f[i]=min(f[i],f[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j]));
		}
	}
	for(int i=t; i<t+m; i++) {
		ans=min(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
