#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string a[30];
int n,l;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
		while(a[i].length()<100) a[i]='0'+a[i];
	string big="0";
	for(int i=1;i<=n;i++)
	{
		if(big<a[i])big=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==big)
		{
			printf("%d\n",i);
			int p=0;
			while(a[i][p]=='0')p++;
			for(int j=p;j<=a[i].length();j++)
			{
				cout<<a[i][j];
			}
		}
	
	}
}
