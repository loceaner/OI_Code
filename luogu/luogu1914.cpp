#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string s;
	int n,l;
	cin>>n;
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s[i]++;
			if(s[i]>'z')
				s[i]='a';
		}
	}
	for(int i=0;i<l;i++)
	{
		cout<<s[i];
	}
	return 0;
}
