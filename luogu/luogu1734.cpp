#include<bits/stdc++.h>
using namespace std;

int dp[10501],s[1005],l;

void init() {
	for(int sum=1,i=1; i<=1000; i++,sum=1) {
		for(int j=2; j<=sqrt(i); j++) {
			if(i%j==0) {
				sum+=j;
				if(j!=i/j) sum+=i/j;
			}
		}
		s[i]=sum;
	}
	s[1]=0;
}

int main() {
	init();
	scanf("%d",&l);
	for(int i=2; i<=l; i++)
		for(int j=l; j>=i; j--)
			dp[j]=max(dp[j-i]+s[i],dp[j]);
	printf("%d\n",dp[l]);
	return 0;
}
