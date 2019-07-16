#include<bits/stdc++.h>
#define maxn 100100
using namespace std;

inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&& c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int n,k,pre[maxn],tot;
int cs[maxn*10];
long long ans=0;
struct bian{
	int x,y,w;
}b[maxn];

int find(int x){
	if(pre[x]==x)return x; 
	return pre[x]=find(pre[x]);
}

bool comp(bian a,bian b){
	return a.w>b.w;
}

int main(){
	int m;
	n=read();k=read();
	for(int i=1;i<=n;i++)pre[i]=i;//首先自己是自己的祖先 
	for(int i=1;i<=k;i++)m=read(),cs[m]=true;
	for(int i=1;i<=n-1;i++){
		b[i].x=read();b[i].y=read();b[i].w=read();
		ans+=b[i].w;
	}
	stable_sort(b+1,b+n,comp);//stable_sort的用法与sort相同，更加稳定 
	for(int i=1;i<=n;i++){
		int u=b[i].x,v=b[i].y,w=b[i].w;
		int fu=find(u),fv=find(v);
		if(cs[fu] && cs[fv])continue;
		pre[fu]=fv;
		
		ans-=w;
		if(cs[fu])cs[fv]=true;
		else if(cs[fv])cs[fu]=true;
	}
	cout<<ans;
	return 0;
}
