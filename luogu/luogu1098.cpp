#include<iostream>
#include<cstdio>
#include<string> 
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int p1,p2,p3,len;
char s[120];

int main() {
	//freopen("expand.in","r",stdin);
	//freopen("expand.out","w",stdout);
	scanf("%d%d%d",&p1,&p2,&p3);
	scanf("%s",s+1);
	len=strlen(s+1);
	s[0]='0';
	s[len+1]='0';
	for(int i=1; i<=len; i++) {
		if(s[i]!='-') {
			cout<<s[i];
			continue;
		}
		if(s[i+1]-s[i-1]==1)continue;
		if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9') {
			if(s[i+1]<=s[i-1]) {
				cout<<s[i];
				continue;
			}
			if(p1==3) {
				for(int j=s[i-1]+1; j<s[i+1]; j++)
					for(int k=1; k<=p2; k++)
						cout<<"*";
				continue;
			}
			if(p3==1) {
				for(int j=s[i-1]+1; j<s[i+1]; j++)
					for(int k=1; k<=p2; k++)
						cout<<char(j);
				continue;
			}
			if(p3==2) {
				for(int j=s[i+1]-1; j>=s[i-1]+1; j--)
					for(int k=1; k<=p2; k++)
						cout<<char(j);
				continue;
			}
		}
		if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z') {
			if(s[i+1]<=s[i-1]) {
				cout<<s[i];
				continue;
			}
			if(p1==3) {
				for(int j=s[i-1]+1; j<s[i+1]; j++)
					for(int k=1; k<=p2; k++)
						cout<<"*";
				continue;
			}
			if(p3==1) {
				if(p1==1) {
					for(int j=s[i-1]+1; j<s[i+1]; j++)
						for(int k=1; k<=p2; k++)
							cout<<char(j);
					continue;
				}
				if(p1==2) {
					for(int j=s[i-1]+1; j<s[i+1]; j++)
						for(int k=1; k<=p2; k++)
							cout<<char(j-32);
					continue;
				}

			}
			if(p3==2) {
				if(p1==1) {
					for(int j=s[i+1]-1; j>=s[i-1]+1; j--)
						for(int k=1; k<=p2; k++)
							cout<<char(j);
					continue;
				}
				if(p1==2) {
					for(int j=s[i+1]-1; j>=s[i-1]+1; j--)
						for(int k=1; k<=p2; k++)
							cout<<char(j-32);
					continue;
				}

			}
		}
		cout<<s[i];
	}
	return 0;
}
