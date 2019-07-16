#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[10];
int main()
{
	int l,r,ans=0;
	cin>>l>>r;
	for(int i=l;i<=r;++i)
	{
		sprintf(s,"%d",i);
		l=strlen(s);
		for(int j=0;j<=l-1;++j)
	      if(s[j]=='2')++ans;
	}
	cout<<ans;
	return 0;
}
