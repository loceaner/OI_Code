#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
#define N 110
#define MOD 1000000007
using namespace std;

inline int read() {
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*f;
}

int n,k;

struct node {
	int a[N][N];
	node() {
		memset(a,0,sizeof(a));
	}
	inline void build() {
		for(int i=1; i<=n; i++)a[i][i]=1;
	}
} a;

node operator *(const node &x, const node &y) {
	node z;
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%MOD)%MOD;
			}
		}
	}
	return z;
}
node ans;

void power() {
	while(k) {
		if(k&1)ans=ans*a;
		a=a*a;
		k>>=1;
	}
}

signed main() {
	n=read();
	k=read();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			a.a[i][j]=read();
		}
	}
	ans.build();
	power();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout<<ans.a[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
