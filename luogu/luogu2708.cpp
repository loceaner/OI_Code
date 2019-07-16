#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int i,m,k;
	string s;
	cin>>s;
	m=s.size();
	k=m-1;
	for(i=1; i<m; ++i)
		if(s[i]==s[i-1])k--;
	if(s[m-1]=='0')k++;
	cout<<k;
	return 0;
}
