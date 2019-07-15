#include<iostream>
using namespace std;

int a[101],b[100];

int main()
{
	int n,s=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	for(int i=1;i<=n;i++)
	{
		a[i]-=sum;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)continue;
		a[i+1]+=a[i];
		s++;
	}
	cout<<s;
	return 0;
}
