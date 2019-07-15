#include<bits/stdc++.h>
using namespace std;
int n,sum=0,ans=0;
int main() {
	cin>>n;
	int j=1;
	for(int i=1; i<n; i++) {
		sum+=i;
		if(sum==n) cout<<j<<" "<<i<<endl;
		while(sum>n) sum-=j,j+=1;
		if(sum==n) cout<<j<<" "<<i<<endl;
	}
	return 0;
}
