#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,p;
int g[30000010],f[30000010];

int power(int a,int b) {
	int ret=1;
	while(b) {
		if(b&1)ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret%p;
}

signed main() {
	scanf("%d%d",&n,&p);
	g[0]=1;
	for(int i=1; i<=n; ++i)
		g[i]=(i*g[i-1])%p;
	f[n]=power(g[n],p-2);
	int k;
	for(int i=n; i>1; --i )
		f[i-1]=f[i]*i%p;
	for(int i=1; i<=n; i++) {
		cout<<f[i]*g[i-1]%p<<'\n';
	}
	return 0;
}

