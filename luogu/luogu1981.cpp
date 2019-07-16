#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int sum,a1,a2;
char sign;

int main() {
	cin>>a1;
	a1%=10000;
	while(cin>>sign) {
		cin>>a2;
		a2%=10000;
		if(sign=='+') {
			sum+=a1;
			sum%=10000;
			a1=a2;
		}
		if(sign=='*') {
			a1*=a2;
			a1%=10000;
		}
	}
	sum+=a1;
	cout<<sum%10000;
	return 0;
}
