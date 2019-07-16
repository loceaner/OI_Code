#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<deque>
#include<algorithm>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

int n,f[100001],w[10001],k[10001],V;

int main() {
	scanf("%d%d",&V,&n);
	for(int i=1; i<=n; i++) scanf("%d%d",&k[i],&w[i]);
	for(int i=1; i<=n; i++)
		for(int j=w[i]; j<=V; j++)
			f[j]=max(f[j],f[j-w[i]]+k[i]);
	printf("%d",f[V]);
	return 0;
}
