#include<bits/stdc++.h>
#define N 5010
using namespace std;

inline int read() {
	char c=getchar();
	int x=0,f=1;
	for(; !isdigit(c); c=getchar())if(c=='-')f=-1;
	for(; isdigit(c); c=getchar())x=x*10+c-48;
	return x*f;
}

int n,m,v;
int f[N];
int t1,t2;
int t[N],c[N],w[N];

int main() {
	t1=read(),t2=read();
	m=read(),n=read();
	for(int i=1; i<=n; i++) {
		t[i]=read();
		t[i]=t2/t1*t[i];
	}
	for(int i=1; i<=m; i++) {
		c[i]=read(),w[i]=read();
	}
	v=read();
	for(int i=1;i<=m;i++){
		for(int j=v;j>=t[c[i]];j--){
			f[j]=max(f[j],f[j-t[c[i]]]+w[i]);
		}
	}
	cout<<f[v];
	return 0;
}
