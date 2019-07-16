#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string a;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a;
		if(a=="TAKAHASHIKUN"||a=="TAKAHASHIKUN."||a=="Takahashikun"||a=="Takahashikun."||a=="takahashikun"||a=="takahashikun.")
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
