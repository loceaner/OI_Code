#include<iostream>
using namespace std;
int n,a[100001];
long long sum;
int main() {
	int i;
	cin>>n;
	for(i=1; i<=n; i++)
		cin>>a[i];
	for(i=2; i<=n; i++)
		sum+=max(a[i],a[i-1]);
	cout<<sum;
	return 0;
}
