#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[4]={0};
	cin>>a[1]>>a[2]>>a[3];
	char A,B,C;
	cin>>A>>B>>C;
	sort(a+1,a+1+3);
	cout<<a[A-'A'+1]<<" "<<a[B-'A'+1]<<" "<<a[C-'A'+1];
	return 0;
 } 
