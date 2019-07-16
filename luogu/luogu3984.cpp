#include<bits/stdc++.h>
using namespace std;
int n,t;
long long ans;
int a[200001];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	n=read();
	t=read();
	a[1]=read();
	for(int i=2; i<=n; i++) {
		a[i]=read();
		if(a[i]-a[i-1]<t)
		{
			ans+=a[i]-a[i-1];
		}
		else ans+=t;
	}
	ans+=t;
	cout<<ans<<"\n";
	return 0;
}
