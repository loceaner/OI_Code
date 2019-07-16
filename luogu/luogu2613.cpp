#include<bits/stdc++.h>
#define ll int
#define MOD 19260817
using namespace std;

inline int read() {
	int m=0,f=1;
	char c=getchar();
	for(; !isdigit(c); c=getchar())if(c=='-')f=-1;
	for(; isdigit(c); c=getchar()) {
		m=m*10+c-48;
		m%=MOD;
	}
	return m*f;
}

ll x,y;
ll a,b;

void exgcd(ll a,ll b,ll &x,ll &y) {
	if(b)exgcd(b,a%b,y,x),y-=(a/b)*x;
	else x=1,y=0;
}

int main() {
	a=read(),b=read();
	if(b==0){
		cout<<"Angry!\n";
		return 0;
	}
	exgcd(b,MOD,x,y);
	x=(x%MOD+MOD)%MOD;
	cout<<a*(long long)(x)%MOD;
	return 0;
}
