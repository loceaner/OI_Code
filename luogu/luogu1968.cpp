#include<bits/stdc++.h>
#define N 110
using namespace std;

double f[N][3],w[N];
int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&w[i]);
	}
	f[1][1]=100;
	f[1][2]=w[1];
	for(int i=2;i<=n;i++){
		f[i][1]=max(f[i-1][1],f[i-1][2]/w[i]*100.000);
		f[i][2]=max(f[i-1][2],f[i-1][1]*w[i]/100.000);
	}
	printf("%.2lf",max(f[n][1],f[n][2]/w[n]*100.000));
	return 0;
}
