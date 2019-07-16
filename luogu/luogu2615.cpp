#include<iostream>
#include<cmath>
using namespace std;
int a[40][40]={0};
int main()
{
	int n,b,k=1,x,y;
	cin>>n;
	b=n/2+1;
	a[x=1][y=b]=k;
	while(k<=n*n)
	{
		if(x==1&&y!=n)a[x=n][++y]=++k;
		if(x!=1&&y==n)a[--x][y=1]=++k;
		if(x==1&&y==n)a[++x][y]=++k;
		if(x!=1&&y!=n)
		{
			if(a[x-1][y+1]==0)a[--x][++y]=++k;
			else a[++x][y]=++k;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
