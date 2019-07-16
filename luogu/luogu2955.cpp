#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if((a[a.size()-1]-'0')%2==0)cout<<"even"<<endl;
		if((a[a.size()-1]-'0')%2==1)cout<<"odd"<<endl;
	}
	return 0;
}
