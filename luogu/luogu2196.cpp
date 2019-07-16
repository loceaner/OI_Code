#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 101;
inline int read() {
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int N,a[MAXN],ca[MAXN][MAXN],f[MAXN],Pre[MAXN],ed;
int main() {
	N=read();
	for(int i=1; i<=N; i++)a[i]=read();
	for(int i=1; i<=N; i++)
		for(int j=i+1; j<=N; j++)
			ca[i][j]=ca[j][i]=read();
	int ans=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=i-1; j++)
			if(ca[i][j]&&f[j]>f[i])f[i]=f[j],Pre[i]=j;
		f[i]+=a[i];
		if(f[i]>ans)ans=f[i],ed=i;
	}
	vector<int> v;
	while(ed) v.push_back(ed),ed=Pre[ed];
	for(int i=v.size()-1; i>=0; i--) printf("%d ",v[i]);
	puts("");
	printf("%d", ans);
	return 0;
}
