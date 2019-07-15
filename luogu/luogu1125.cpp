#include<iostream>
#include<cstring>
using namespace std;
string s;
int n,i,da,xiao=999,c[27];
int main() {
	cin>>s;
	n=s.length();
	for(i=0; i<n; i++)
		c[s[i]-'a']++;
	for(i=0; i<26; i++) {
		if(0<c[i]&&c[i]<xiao)xiao=c[i];
		if(c[i]>da)da=c[i];
	}
	da-=xiao;
	for(i=2; i<da/2; i++)
		if(da%i==0) {
			n=0;
			break;
		}
	if(n&&da!=1&&da)cout<<"Lucky Word"<<endl<<da;
	else cout<<"No Answer"<<endl<<0;
}
