#include<bits/stdc++.h>
using namespace std;

int n,sum;
bool a[100000000];

int main() {
	cin>>n;
	if(n<2) {
		cout<<"0";
		return 0;
	}
	sum=n;
	sum-=n/2-1;
	a[1]=true;
	int l=sqrt(n);
	for(int i=3; i<=l; i+=2) {
		if(a[i]==false) {
			for(int j=i*2; j<=n; j+=i) {
				if(a[j]==false&&j%2!=0)
					sum--;
				a[j]=true;
			}
		}
	}
	cout<<sum-1<<'\n';
	return 0;
}
