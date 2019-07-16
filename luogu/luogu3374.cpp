#include<bits/stdc++.h>
using namespace std;

const int N=500100;
int n,m,a;
int ch,x,y,v;
int sum[N];

int lowbit(int x) {
	return x&(-x);
}

void update(int p,int v) {
	while(p<=n) {
		sum[p]+=v;
		p+=lowbit(p);
	}
}

int query(int p) {
	int ans=0;
	while(p) {
		ans+=sum[p];
		p-=lowbit(p);
	}
	return ans;
}

inline int read() {
	char c=getchar();
	int x=0,f=1;
	for(; !isdigit(c); c=getchar())if(c=='-')f=-1;
	for(; isdigit(c); c=getchar())x=x*10+c-48;
	return x*f;
}

int main() {
	n=read(),m=read();
	for(int i=1; i<=n; i++) {
		a=read();
		update(i,a);
	}
	for(int i=1; i<=m; i++) {
		ch=read();
		if(ch==1) {
			x=read(),y=read();
			update(x,y);
		}
		if(ch==2) {
			x=read(),y=read();
			cout<<query(y)-query(x-1)<<endl;
		}
	}
	return 0;
}
