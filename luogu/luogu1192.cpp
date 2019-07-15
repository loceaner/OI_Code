#include <bits/stdc++.h>
using namespace std;
int n,k;
const int mod=100003;
int a[1000000];
int main() {
	scanf("%d%d",&n,&k);
	a[0]=a[1]=1;
	for(int i=2; i<=n; ++i)
		if(i<=k)
			a[i]=a[i-1]*2%mod;
		else {
			a[i]=a[i-1]*2-a[i-k-1],a[i]%=mod;
		}
	cout<<(a[n]+mod)%mod<<endl;
	return 0;
}
