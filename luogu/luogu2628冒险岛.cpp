#include<bits/stdc++.h>
using namespace std;
string s;
int n,a,cishi=-1,tot=0;
int main() {
	getline(cin,s);
	scanf("%d",&n);
	int length=s.length()-1;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a);
		cishi+=a;
		if(cishi>=length) cishi=length-1;
		if(s[cishi]=='>'&&s[cishi+1]=='>'&&s[cishi+2]=='>')
			while(s[cishi]=='>')cishi++;
		else if(s[cishi]=='*'&&s[cishi+1]=='*'&&s[cishi+2]=='*') {
			while(s[cishi+tot]=='*')tot++;
			cishi-=tot;
		}
		if(cishi<0)cishi=0;
		if(cishi>=length)cishi=length-1;
	}
	cout<<cishi+1<<' '<<length-1-cishi;
	return 0;
}
