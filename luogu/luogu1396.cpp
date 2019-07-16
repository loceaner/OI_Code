#include<bits/stdc++.h>
using namespace std;

int n,m,s,t,pre[200001];
struct node{
	int x,y,w;
}bian[100001];

bool comp(node a,node b){
	return a.w<b.w;
}

inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&& c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int find(int x){
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}

int main(){
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=m;i++){
		bian[i].x=read();
		bian[i].y=read();
		bian[i].w=read();		
	}
	for(int i=1;i<=n;i++){
		pre[i]=i;
	}
	sort(bian+1,bian+1+m,comp);
	for(int i=1;i<=m;i++){
		int r1=find(bian[i].x);
		int r2=find(bian[i].y);
		if(r1!=r2)pre[r1]=r2;
		if(find(s)==find(t)){
			cout<<bian[i].w<<'\n';
			return 0;
		}
	}
	return 0;
}
