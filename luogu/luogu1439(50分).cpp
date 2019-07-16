#include<bits/stdc++.h>
using namespace std;

int a[101001],b[101001];
int f[10000][10001];
int n;

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(a[i]==b[j]) {
				f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		}
	}
	cout<<f[n][n]<<'\n';
	return 0;
}
