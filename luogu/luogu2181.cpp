#include<bits/stdc++.h>
using namespace std;
unsigned long long n,ans;
int main() {
	cin>>n;
	ans=n*(n-1)/2*(n-2)/3*(n-3)/4;
	cout<<ans;
	return 0;
}
