#include<bits/stdc++.h>
#define N 12888
using namespace std;

int f[N];
int a[N];
int c[N],w[N];
int n,m;

inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*f;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		w[i]=read(),c[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int v=m;v>=w[i];v--){
			f[v]=max(f[v-w[i]]+c[i],f[v]);
		}
	}
	cout<<f[m]<<'\n';
	return 0;
} 
