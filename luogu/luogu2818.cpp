#include<bits/stdc++.h>
#define ll long long
using namespace std;

char s[1010];
long long ans,n;

int main() {
	cin>>n;
	cin>>s;
	for(int i=0; s[i]; i++) {
		ans=(ans*10+s[i]-'0')%n;
	}
	if(ans==0)cout<<n;
	else cout<<ans;
	return 0;
}
