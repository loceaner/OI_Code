#include<iostream>
using namespace std;
int a[1001],b[1001];
int dp[1001];
int main() {
	int t=0,m=0;
	cin>>t>>m;
	for(int i=1; i<=m; ++i) {
		cin>>a[i]>>b[i];
	}
	for(int i=1; i<=m; ++i) {
		for(int j=t; j>=a[i]; --j) {
			dp[j]=std::max(dp[j],dp[j-a[i]]+b[i]);
		}
	}
	cout<<dp[t];
	return 0;
}
