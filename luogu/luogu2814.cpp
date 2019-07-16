#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
map<string,string>da;
string find(string x) {
	if(x!=da[x])
		da[x]=find(da[x]);
	return  da[x];
}
string s,s1;
int main() {
	char str;
	cin>>str;
	while(str!='$') {
		cin>>s;
		if(str=='#') {
			s1=s;
			if(da[s]=="") da[s]=s;
		} else if(str=='+')
			da[s]=s1;
		else
			cout<<s<<" "<<find(s)<<endl;
		cin>>str;
	}
	return 0;
}
