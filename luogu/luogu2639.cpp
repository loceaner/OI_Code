#include<bits/stdc++.h>
#define N 50001
#define MD 10001
using namespace std;

int dp[N],w[MD],c[MD],n,m;

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		w[i]=c[i];
	}
	for(int i=1;i<=n;i++){
		for(int v=m;v>=c[i];v--){
			dp[v]=max(dp[v],dp[v-c[i]]+w[i]);
		}
	}
	cout<<dp[m]<<'\n';
	return 0;
}
