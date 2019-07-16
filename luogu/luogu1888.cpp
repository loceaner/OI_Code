#include<iostream>
#include<algorithm>
using namespace std;
long k(long x, long y)
{
    int r;
    r=x%y;
    while (r!=0)
    {
      x=y; y=r;
      r=x%y;
    } 
    return y;
}
int main()
{
	int s,a,b,c;
	cin>>a>>b>>c;
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	s=k(a,c);
	a=a/s;
	c=c/s;
	cout<<a<<"/"<<c<<endl;
}
