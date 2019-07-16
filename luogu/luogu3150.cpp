#include<iostream>
using namespace std;
unsigned long long shu;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>shu;
		if(shu%2==1)cout<<"zs wins"<<endl;
		if(shu%2==0)cout<<"pb wins"<<endl;
	}
	return 0;
}
