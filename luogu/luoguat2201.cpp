#include"bits/stdc++.h"
using namespace std;

string s,b;

int main() {
	cin>>s;
	b=s;
	reverse(s.begin(),s.end());
	for(int i=0; i<s.size(); ++i) {
		if(s[i]=='b') s[i]='d';
		else if(s[i]=='d') s[i]='b';
		else if(s[i]=='p') s[i]='q';
		else if(s[i]=='q') s[i]='p';
	}
	if(s==b) cout<<"Yes";
	else cout<<"No";
	return 0;
}
