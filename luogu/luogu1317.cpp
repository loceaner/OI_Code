#include<bits/stdc++.h>//懒人头文件
using namespace std;
long long a[10001],b[10001];
int main()
{
	long long n,c=0,z=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i+1])b[++c]=a[i];
	}
	for(int i=1;i<=c;i++)
	{
		if((b[i-1]>b[i])&&(b[i]<b[i+1]))
		  	z++;
	}
	cout<<z;
	return 0;
}
