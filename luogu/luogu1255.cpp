#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int n,l=1,f[5001][5001];

void luoti(int m)
{
	int i;
	for(i=1;i<=l;i++)
	{
		f[m][i]=f[m-1][i]+f[m-2][i];
	}
	for(i=1;i<=l;i++)
	{
		if(f[m][i]>=10)
		{
			f[m][i+1]+=f[m][i]/10;
			f[m][i]=f[m][i]%10;	
			if(f[m][l+1])
			l++;
		}
	}
}

int main()
{
	scanf("%d",&n);
	f[1][1]=1;
	f[2][1]=2;
	for(int i=3;i<=n;i++)
	{
		luoti(i);
	}
	for(int i=l;i>=1;i--)
	{
		printf("%d",f[n][i]);
	}
	return 0;
}
