#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 30
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
int f[N][N];

signed main() {
	memset(f,0x3f,sizeof(f));
	n=read(),k=read();
	for(int i=1; i<=n; i++) {
		int x;
		x=read();
		f[i][i%n+1]=f[i%n+1][i]=x;
	}
	for(int i=1; i<=k; i++) {
		char a,b;
		int x;
		cin>>a>>b>>x;
		if(f[a-'A'+1][b-'A'+1]<1000)f[a-'A'+1][b-'A'+1]=f[b-'A'+1][a-'A'+1]=max(f[a-'A'+1][b-'A'+1],x);
		else f[a-'A'+1][b-'A'+1]=f[b-'A'+1][a-'A'+1]=x;
	}
	for(int i=1; i<=n; i++)if(f[i][i]>1000)f[i][i]=0;
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i!=j&&i!=k&&j!=k&&f[i][j]>f[i][k]+f[k][j]) {
					f[j][i]=f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	char a,b;
	cin>>a>>b;
	cout<<f[a-'A'+1][b-'A'+1];
	return 0;
}
