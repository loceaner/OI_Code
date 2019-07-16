#include<bits/stdc++.h>
using namespace std;
long long a,dan,minn=99999999999,ans,l;
int main() {
	cin>>a;
	for(int s=0; s<a; s++) {
		cin>>l;
		ans+=l;
		if(l%2==1) { 
			dan++;
			minn=min(minn,l);
		}
	}
	if(dan%2==1)ans-=minn;
	cout<<ans<<endl;
}
