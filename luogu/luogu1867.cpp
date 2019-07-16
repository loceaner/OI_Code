#include<iostream>
#include<cmath>
#include<cstdio> 
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	double x=10,a,b;
	int sum=0;
	for(int i=1; i<=n; i++) {
		scanf("%lf%lf",&a,&b);
		x-=a;
		if(x>10)    x=10;
		if(x<=0)    break;
		else        sum+=b;
	}
	int k=0;
	while(sum>=pow(2,k)) { 
		sum-=pow(2,k);
		k++;
	}
	cout<<k<<" "<<sum;
}
