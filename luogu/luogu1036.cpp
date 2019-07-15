#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool vis[21];
int ans,k,n,x[21];
int pd(int k) {
	for(int j=2; j*j<=k; ++j)
		if(k%j==0) return 0;
	return 1;
}
void read(int &x) {
	x=0;
	int f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+(int)ch-48;
		ch=getchar();
	}
	x=x*f;
}
void dfs(int pos,int sum,int siz) {
	if(siz==k) {
		if(pd(sum))
			ans++;
		return ;
	}
	for(int i=1; i<=n; ++i) {
		if(!vis[i]&&i>pos) { //没被访问，并且从下一个开始搜索
			vis[i]=1;
			dfs(i,sum+x[i],siz+1);
			vis[i]=0;
		}
	}
}
int main() {
	read(n);
	read(k);
	for(int i=1; i<=n; ++i)
		read(x[i]);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
