#include<iostream>
using namespace std;
int main() {
	long long x,n,sum=1,i;
	cin>>x>>n;
	for(i=0; i<n; i++) {
		sum=sum+sum*x;
	}
	cout<<sum;
	return 0;
}
