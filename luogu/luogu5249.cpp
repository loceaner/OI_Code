#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,k;
double p,sp,ans,s[N],pw1[N],pw2[N];
double qpow(double a,int b) {
	double ret=1;
	while(b) {
		if(b&1)ret*=a;
		a*=a,b>>=1;
	}
	return ret;
}
int main() {
	cin>>p>>n>>k;
	if(n==1) {
		cout<<1;
		return 0;
	}
	for(int i=1; i<=1e5; i++)s[i]=1-qpow(1-p,i);
	for(int i=1; i<=1e5; i++)pw1[i]=qpow(s[i],k-1),pw2[i]=qpow(s[i],n-k);
	for(int i=1; i<=1e5; i++)
		if(k==n)ans+=pw1[i]*(s[i]-s[i-1]);
		else if(k==1)ans+=pw2[i-1]*(s[i]-s[i-1]);
		else ans+=pw1[i]*pw2[i-1]*(s[i]-s[i-1]);
	printf("%0.9f",ans);
}
