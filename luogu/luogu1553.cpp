#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

string s;
char a[101];
int flag=0;
int d;

int main() {
	getline(cin,s);
	int l=s.length();
	for(int i=0; i<l; i++) {
		if(s[i]=='/') {flag=1;d=i-1;break;}
		if(s[i]=='%') {flag=2;break;}
		if(s[i]=='.') {flag=3;d=i-1;break;}
	}
	if(flag==1) {
		int len=d+1;
		while(s[d]=='0') d--;
		if(d<0)cout<<'0';
		for(int i=d; i>=0; i--) cout<<s[i];
		printf("/");
		while(s[l-1]=='0') l--;
		for(int i=l-1; i>len; i--) cout<<s[i];
		return 0;
	}
	if(flag==2) {
		int len=s.length()-2;
		while(s[len]=='0') len--;
		if(len<0)cout<<'0';
		for(int i=len; i>=0; i--) cout<<s[i];
		cout<<'%';
		return 0;
	}
	if(flag==3) {
		int len=d+1;
		while(s[d]=='0') d--;
		if(d<0)cout<<'0';
		for(int i=d; i>=0; i--) cout<<s[i];
		printf(".");
		while(s[l]=='0') l--;
		len++;
		while(s[len]=='0') len++;
		len--;
		if(l-1==len)cout<<'0';
		for(int i=l-1; i>len; i--) cout<<s[i];
		return 0;
	}
	if(flag==0) {
		int len=s.length()-1;
		while(s[len]=='0') len--;
		for(int i=len; i>=0; i--) cout<<s[i];
		if(len<0)cout<<'0';
		return 0;
	}
}
