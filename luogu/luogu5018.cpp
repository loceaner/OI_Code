#include<cstdio>
using namespace std;
int v[1000005],ch[1000005][2],c[1000005],n,ans;
bool same(int a,int b) { 
	if(a==b)return 1;
	if(!a||!b)return 0;
	return v[a]==v[b]&&same(ch[a][1],ch[b][2])&&same(ch[a][2],ch[b][1]);
}
void dfs(int i) { 
	if(!i)return;
	dfs(ch[i][1]);
	dfs(ch[i][2]);
	c[i]=1+c[ch[i][1]]+c[ch[i][2]];
	v[i]=v[i]+v[ch[i][1]]+v[ch[i][2]];
	if(ans<c[i]&&same(ch[i][1],ch[i][2]))ans=c[i];
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&v[i]);
	v[0]=1005;
	for(int i=1; i<=n; i++)
		for(int k=1; k<=2; ++k) {
			scanf("%d",&ch[i][k]);
			if(ch[i][k]==-1)ch[i][k]=0;
		}
	dfs(1);
	printf("%d",ans);
	return 0;
	//return 0!!!!!!!!
}
