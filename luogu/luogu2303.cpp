#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

ll oula(ll x) {
	ll ans=x,tp=sqrt(x);
	for(ll i=2; i<=tp; ++i)
		if(x%i==0) {
			ans=ans-ans/i;
			while(x%i==0)  x/=i;
		}
	if(x>1)  ans=ans-ans/x;
	return ans;
}

ll n,ans=0;

inline int read() {
	int ret=0,ff=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*ff;
}

signed main() {
	n=read();
	int x=sqrt(n);
	for(int i=1; i<=x; i++) {
		if(n%i==0) {
			ans+=oula(n/i)*i;
			if(i*i!=n) ans+=oula(i)*(n/i);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
