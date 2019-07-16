#include<bits/stdc++.h>
using namespace std;
inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(c < '0' || c > '9') {
		if(c == '-') f = -1 ;
		c = getchar();
	}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

long long ans=0;
int n,m;
int a,b;
int pre[1001];

int find(int x) {
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}

void join(int x,int y) {
	int r1=find(x),r2=find(y);
	if(r1!=r2) {
		pre[r2]=r1;
	}
}

int main() {
	while(true) {
		ans=0;
		n=read();
		if(n==0)return 0;
		m=read();
		for(int i=1; i<=n; i++)pre[i]=i;
		for(int i=1; i<=m; i++) {
			a=read();
			b=read();
			if(find(a)!=find(b))join(find(a),find(b));
		}
		for(int j=1; j<=n; j++) {
			if(pre[j]==j)ans++;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
