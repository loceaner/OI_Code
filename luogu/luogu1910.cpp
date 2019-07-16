#include <bits/stdc++.h>
#define N 1111
using namespace std;

int n,m,x;
int a[N],b[N],c[N];
int f[N][N];

inline int read() {
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*f;
}

int main() {

	n=read(),m=read(),x=read();
	
	for(int i=1; i<=n; i++) {
		a[i]=read();
		b[i]=read();
		c[i]=read();
	}

	for(int i=1; i<=n; i++) {
		for(int j=m; j>=b[i]; j--) {
			for(int k=x; k>=c[i]; k--) {
				f[j][k]=max(f[j][k],a[i]+f[j-b[i]][k-c[i]]);
			}
		}
	}
	
	cout<<f[m][x];
	
	return 0;
}
