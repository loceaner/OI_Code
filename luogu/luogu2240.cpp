#include<bits/stdc++.h>
using namespace std;

int n,i,f[1500002];

int main() {
	scanf("%d",&n);
	f[0]=1;
	f[1]=1;
	for(i=2; i<=n; i++)
		f[i]=f[i-2]+f[i/2];
	printf("%d",f[n]);
	return 0;
}
