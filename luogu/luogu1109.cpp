#include<iostream>
#include<cstdio>//������ô��һ��Ҫ����� 
#include<algorithm>
#include<cmath>
using namespace std;
int sjp[110];
int main() {
	int n,left,right,a=0,b=0,sum=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>sjp[i];
		sum+=sjp[i];
	}
	cin>>left>>right;
	for(int i=1; i<=n; i++) {
		if(sjp[i]>right) a+=sjp[i]-right;
		if(sjp[i]<left) b+=left-sjp[i];
	}
	if(sum>n*right) cout<<"-1";
	else cout<<max(a,b);
	return 0;
}
