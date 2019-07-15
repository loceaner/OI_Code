//按照题解1做法来做的 
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string a[21];
bool comp(string x,string y)
{
	return x+y>y+x;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,comp);
	for(int i=1;i<=n;i++)cout<<a[i];
}
