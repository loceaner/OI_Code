#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 1010
using namespace std;

int a[N][N];
int n;

inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-1')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*f;
}

int main() {
	//scanf("%d",&n);
	n=read();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			//scanf("%d",&a[i][j]);
			a[i][j]=read();
		}
	}
	for(int i=n-1; i>=1; i--) {
		for(int j=1; j<=i; j++) {
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
		}
	}
	cout<<a[1][1]<<'\n';
	return 0;
}
