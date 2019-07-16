#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long lt;

lt read() {
	lt f=1,x=0;
	char ss=getchar();
	while(ss<'0'||ss>'9') {
		if(ss=='-')f=-1;
		ss=getchar();
	}
	while(ss>='0'&&ss<='9') {
		x=x*10+ss-'0';
		ss=getchar();
	}
	return f*x;
}

const int maxn=500010;
int n,k,cnt;
lt a[maxn],b[maxn];
struct node {
	lt val;
	int num;
} mi[maxn];
int pre[maxn],nxt[maxn],judge[maxn];
lt ans;

void swapp(int x,int y) {
	node tt=mi[x];
	mi[x]=mi[y];
	mi[y]=tt;
}

void ins(lt val,int num) {
	mi[++cnt].val=val;
	mi[cnt].num=num;
	int p=cnt;
	while(p>1) {
		if(mi[p>>1].val>mi[p].val) {
			swapp(p,p>>1);
			p>>=1;
		} else break;
	}
}

void pop() {
	mi[1]=mi[cnt--];
	int p=1,s=p<<1;
	while(s<=cnt) {
		if(s<cnt&&mi[s].val>mi[s+1].val) s++;
		if(mi[p].val>mi[s].val) {
			swapp(p,s);
			p=s;
			s=p<<1;
		} else break;
	}
}

int main() {
	n=read();
	k=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<n; ++i) {
		b[i]=a[i+1]-a[i];
		ins(b[i],i);
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	b[0]=b[n]=2e9;
	nxt[0]=1;
	pre[n+1]=n;
	while(k--) {
		while(judge[mi[1].num]) pop();
		int val=mi[1].val,num=mi[1].num;
		pop();

		ans+=val;
		b[num]=b[pre[num]]+b[nxt[num]]-b[num];
		judge[pre[num]]=judge[nxt[num]]=1;

		pre[num]=pre[pre[num]];
		nxt[pre[num]]=num;
		nxt[num]=nxt[nxt[num]];
		pre[nxt[num]]=num;

		ins(b[num],num);
	}
	printf("%lld",ans);
	return 0;
}
