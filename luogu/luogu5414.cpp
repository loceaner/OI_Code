#include<bits/stdc++.h>
#define N 2000
using namespace std;

int T,n;
int a[N],b[N];

int main() {
	scanf("%d",&T);
	while(T--) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<i; j++)
				if(a[j]<=a[i])
					b[i]=max(b[i],b[j]);
			b[i]+=a[i];
		}
		int maxn=-0x3f;
		int ans=0;
		for(int i=0; i<n; i++) {
			if(b[i]>maxn)maxn=b[i];
			ans+=a[i];
		}
		ans-=maxn;
		cout<<ans<<'\n';
	}
	return 0;
}
