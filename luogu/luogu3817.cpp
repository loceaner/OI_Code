#include<bits/stdc++.h>
using namespace std;

long long n,a[100010],x,ans,yy;

int main() {
	scanf("%lld%lld",&n,&x);
	for (int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		if(a[i]+a[i-1]>x)yy=a[i]+a[i-1]-x,a[i]-=yy,ans+=yy;
	}
	printf("%lld\n",ans);
	return 0;
}
