#include<bits/stdc++.h>
#define N 10100
#define INF 0x7f
using namespace std;

int a[N],b[N],c[N];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		b[i]=1;
		for(int j=1; j<i; j++) {
			if(a[i]>a[j]&&b[i]<b[j]+1) {
				b[i]=b[j]+1;
			}
		}
	}
	for(int i=n; i>0; i--) {
		c[i]=1;
		for(int j=n; j>i; j--) {
			if(a[i]>a[j]&&c[i]<c[j]+1) {
				c[i]=c[j]+1;
			}
		}
	}
	int maxn=-INF;
	for(int i=1; i<=n; i++) {
		if (b[i]+c[i]>maxn)
			maxn=b[i]+c[i];
	}
	maxn=n-maxn+1;
	cout<<maxn<<'\n';
	return 0;
}
