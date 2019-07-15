#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int w,n,a[30001],sum;
int main() {
	scanf("%d%d",&w,&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1,j=n; i<=j; j--) {
		if(a[i]+a[j]<=w) {
			sum++;
			i++;
		} else sum++;
	}
	printf("%d",sum);
	return 0;
}
