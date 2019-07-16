#include<iostream>
using namespace std;
string s;
int m,cur;
int main() {
	cin>>m>>s;
	for(int i=s.length()-1; i>=0; i--) 
		if(s[i]!='0') { 
			cur=i;
			break;
		}
	for(int i=0; i<s.length(); i++)
		if(s[i]!='0'&&i!=cur)
			cout<<s[i]<<"*"<<m<<"^"<<s.length()-i-1<<"+";
		else if(s[i]!='0'&&i==cur)
			cout<<s[i]<<"*"<<m<<"^"<<s.length()-i-1;
	return 0;
}
