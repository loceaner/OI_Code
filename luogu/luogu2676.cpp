#include<iostream>
#include<algorithm>
using namespace std;
int a[20010];
bool comp(int a,int b) {
	return a>b;
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n,comp);
	for(int i=1; i<=n; i++) {
		m-=a[i];
		if(m<=0) {
			cout<<i;
			return 0;
		}
	}
}
