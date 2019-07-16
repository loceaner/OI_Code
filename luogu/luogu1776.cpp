#include<bits/stdc++.h>
using namespace std;

const int N=2010,W=40010;
int ln,n,m;
int v[N],w[N],f[W];

int main() {
	scanf("%d%d",&ln,&m);
	for (int i=0; i<ln; ++i) {
		int v1,w1,c;
		scanf("%d%d%d",&v1,&w1,&c);
		for (int j=1; j<=c; j*= 2) {
			++n;
			v[n]=v1*j;
			w[n]=w1*j;
			c-=j;
		}
		if (c>0) {
			++n;
			v[n]=v1*c;
			w[n]=w1*c;
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=m; j>=w[i]; --j) {
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	printf("%d\n",f[m]);
}

