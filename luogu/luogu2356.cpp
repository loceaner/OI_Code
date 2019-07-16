#include<iostream>
#include<cstdio>
using namespace std;

int a[1001][1001];
int shu=0,co=0,n,sum=0;

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)shu++;
		}
	}
	if(shu==0) {
		cout<<"Bad Game!"<<endl;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(a[i][j]==0) {
				sum=0;
				for(int k=1; k<=n; k++) {
					sum+=a[k][j]+a[i][k];
				}
				co=max(co,sum);
			}
		}
	}
	cout<<co;
	return 0;
}
