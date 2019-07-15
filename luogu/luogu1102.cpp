#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
map<long long,int>ma;
long long n,c,ans;
long long num[200010];
int main() {
	scanf("%lld%lld",&n,&c);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&num[i]);
		ma[num[i]]++;
	}
	for(int i=1; i<=n; i++)
		if(ma[num[i]+c])
			ans+=ma[num[i]+c];
	cout<<ans;
}
