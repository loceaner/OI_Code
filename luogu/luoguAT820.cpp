#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];
int main()
{
	int n,b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[1]<<endl;
	return 0;
}
