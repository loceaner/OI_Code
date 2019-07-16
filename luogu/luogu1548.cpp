#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int n,m,s1=0,s2=0;
	cin>>n>>m;
	s2+=((m+1)*(n+1)*m*n)/4;
	for(/*muyouchushitiaojian*/; m>=1&&n>=1; m--,n--)
		s1+=m*n;
	cout<<s1<<" "<<s2-s1;
	return 0;
}
