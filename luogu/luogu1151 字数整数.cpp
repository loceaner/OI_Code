#include<bits/stdc++.h>
using namespace std;
bool bbll;
int main() {
	int k,a1;
	cin>>k;
	for(int i=10000; i<=30000; i++) {
		if(i/100%k==0)
			if((i/10-i/10000*1000)%k==0)
				if((i-i/1000*1000)%k==0) cout<<i<<endl,bbll=1;
	}
	if(!bbll) cout<<"No";
	return 0;
}
