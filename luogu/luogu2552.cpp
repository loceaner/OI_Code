#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int a,b;
	scanf("%lld%lld",&a,&b);
	if(a>b) swap(a,b);
	int temp=abs(a-b);
	int ans=temp*(1.0+sqrt(5.0))/2.0;
	if(ans==a) printf("0\n");
	else printf("1\n");
	return 0;
}
