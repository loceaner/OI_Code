#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	const int N=1e5+5;
	int n,m,p1;
	long long c[N],s1,s2;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%lld",&c[i]);
	scanf("%d%d%lld%lld",&m,&p1,&s1,&s2);
	c[p1]+=s1;
	long long sum=0,mn=1LL<<62;
	for(int i=1; i<=n; ++i) sum+=1LL*(i-m)*c[i];
	int ans;
	for(int i=1; i<=n; ++i) {
		long long now=sum+1LL*(i-m)*s2;
		if(now<0) now=-now;
		if(now<mn) mn=now,ans=i;
	}
	printf("%d\n",ans);
	return 0;
}
