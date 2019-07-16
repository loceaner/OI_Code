#include <bits/stdc++.h>
#define N 1111
using namespace std;

int n,m,x;
int a,b,c;
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
		a=read();b=read();c=read();
		for(int j=m; j>=b; j--) {
			for(int k=x; k>=c; k--) {
				f[j][k]=max(f[j][k],a+f[j-b][k-c]);
			}
		}
	}
	
	cout<<f[m][x];
	
	return 0;
}
