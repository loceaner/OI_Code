#include<bits/stdc++.h>
#define N 100010
using namespace std;

map<int,bool>f;
int a[N],b[N];
int n,m;

inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*f;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){a[i]=read();}
	for(int i=1;i<=m;i++){b[i]=read();f[b[i]]=true;}
	for(int i=1;i<=n;i++){
		if(f[a[i]])cout<<a[i]<<" ";
	}
	return 0;
}
