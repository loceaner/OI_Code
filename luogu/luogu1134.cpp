#include<iostream>
#include<cstdio>
using namespace std;

long long int n,ans=1;

int main() {
	long long int n,ans=1;
	cin>>n;
	for(int i=1; i<=n; i++) {
		ans=ans*i;
		while(ans%10==0)
			ans/=10;
		ans%=1000000;
	}
	cout<<ans%10;
	return 0;
}
