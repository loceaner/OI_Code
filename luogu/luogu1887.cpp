#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,ans,n;
	cin>>a>>b;
	n=a%b;ans=a/b;
	for(int i=n; i<b; ++i)
	{
		cout<<ans<<" ";	
	}
	for(int i=0; i<n; ++i)
	{
		cout<<ans+1<<" ";	
	}
}
