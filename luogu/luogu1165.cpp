#include<bits/stdc++.h>
using namespace std;
int n,a,x,z,ans[200001];
int main() {
	cin>>n;
	ans[0]=0;
	for(int i=1; i<=n; ++i) {
		cin>>a;
		if(a==0) {
			cin>>x;
			z++;
			ans[z]=max(ans[z-1],x);
		}
		if(a==1) {
			if (z!=0)z--;
		}
		if(a==2) {
			cout<<ans[z]<<'\n';
		}
	}
	return 0;
}

