#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b,gc=0,gx,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		gx=gc+a+b-8;	
	    gc=gx;
		sum+=gx;
	}
	cout<<sum;
}
//����⣬���������������˵Ľ��������,Խ����Խ���ˡ������� 
