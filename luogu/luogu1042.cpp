#include<bits/stdc++.h>
using namespace std;

int vic[65001];
int a,b;
char s;

int main() {
	for(int i=1; cin>>s&&s!='E'; i++) {
		if(s=='W')vic[i]=1;
		if(s=='L')vic[i]=2;
	}
	for(int i=1; 1; i++) {
		if(vic[i]==1)a++;
		if(vic[i]==2)b++;
		if(vic[i]==0) {
			cout<<a<<':'<<b<<'\n'<<'\n';
			break;
		}
		if(a-b>=2||b-a>=2){
			if(a>=11||b>=11){
				cout<<a<<':'<<b<<'\n';
				a=0,b=0;
			}
		}
	}
	a=0,b=0;
	for(int i=1;1;i++){
		if(vic[i]==1)a++;
		if(vic[i]==2)b++;
		if(vic[i]==0) {
			cout<<a<<':'<<b;
			break;
		}
		if(a-b>=2||b-a>=2){
			if(a>=21||b>=21){
				cout<<a<<':'<<b<<'\n';
				a=0,b=0;
			}
		}
	}
	return 0;
}
