#include<bits/stdc++.h>
using namespace std;

int a[99999999];
int n,m;

inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*f;
}

int main(){
	int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=m;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=99999999;i++){
		if(a[i]==2)cout<<i<<" ";
	}
}
