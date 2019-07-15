#include<bits/stdc++.h>
using namespace std;

string s;
int n;
bool flag=false;

int main() {
	cin>>s>>n;
	if(s=="10")
	{
		cout<<"0";
		return 0;
	}
	int len=s.size();
	for(int i=0; i<n; i++) {
		for(int j=0; j<len-1; j++) {
			if(s[j]>s[j+1]) {
				for(int k=j; k<len-1; k++)
					s[k]=s[k+1];
				break;
			}
		}
		len--;
	}
	for(int i=0; i<len; i++) {
		if(s[i]!='0')
			flag=true;
		if(flag)
			cout<<s[i];
	}
	cout<<endl;
	return 0;
}
