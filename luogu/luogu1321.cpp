#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	int boy=0,girl=0;
	string st;
	cin>>st;
	for(int i=0;i<=st.length();i++)
	{
		if(st[i]=='b'||st[i+1]=='o'||st[i+2]=='y')
		{
			boy++;
		}
		if(st[i]=='g'||st[i+1]=='i'||st[i+2]=='r'||st[i+3]=='l')
		{
			girl++;
		}
	}
	cout<<boy<<endl<<girl<<endl;
	return 0;
}
