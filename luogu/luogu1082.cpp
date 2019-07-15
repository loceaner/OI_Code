#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll x,y;

void exgcd(ll a,ll b,ll &x,ll &y){
	if(b)exgcd(b,a%b,y,x),y-=(a/b)*x;
	else {x=1,y=0;return;}
}

int main(){
	ll a,b;
	cin>>a>>b;
	exgcd(a,b,x,y);
	while(x<0){
		x+=b;
	}
	x%=b;
	cout<<x<<'\n';
	return 0;
}
