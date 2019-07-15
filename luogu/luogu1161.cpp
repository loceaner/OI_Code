#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,k,m;
double a;
int f[1000001];
int main() {
	cin>>n;
	for(i=1; i<=n; i++) {
		cin>>a>>t;
		for(j=1; j<=t; j++) {
			if(f[(int)(a*j)]==0)f[(int)(a*j)]=1;
			else f[(int)(a*j)]=0;
		}
	}
	for(i=1; i<=2147483647; i++)
		if(f[i]==1) {
			cout<<i;
			return 0;
		}
	return 0;
}
