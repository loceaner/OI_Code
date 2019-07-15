#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
string a,b,c;
char d[666];
int s[666],i,e[666];
int main() {
	cin>>a>>b>>c;
	for(i=0; i<a.size(); ++i) {
		if(s[a[i]]==0)s[a[i]]=b[i];
		else if(s[a[i]]!=b[i]) {
			cout<<"Failed";
			return 0;
		}
		e[b[i]]++;
	}
	for(i='A'; i<='Z'; ++i)
		if(s[i]==0||e[i]==0) {
			cout<<"Failed";
			return 0;
		}
	for(i=0; i<c.size(); ++i) {
		d[i]=s[c[i]];
		cout<<d[i];
	}
	return 0;
}
