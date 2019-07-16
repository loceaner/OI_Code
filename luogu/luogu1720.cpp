#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	double f,a=(1+sqrt(5))/2,b=(1-sqrt(5))/2;
	cin>>n;
	f=(pow(a,n)-pow(b,n))/sqrt(5);
	printf("%.2lf",f);
	return 0;
}
