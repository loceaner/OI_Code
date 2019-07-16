#include<cstdio>
#include<iostream>
#define MaxN 105
#define MaxM 10000+10
using namespace std;

int f[MaxN];
bool d[MaxM];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&f[i]);
	}
	for(int c=1; c<=n; c++)
		for(int a=1; a<=n; a++)
			for(int b=1; b<=n; b++)
				if((f[c]==f[a]+f[b])&&(a!=b))
					d[f[c]]=true;
	int ans=0;
	for(int i=1; i<=n; i++)
		if(d[f[i]])	ans++;
	printf("%d\n",ans);
	return 0;
}
