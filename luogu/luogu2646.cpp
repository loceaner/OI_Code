#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
	long long n=0,a=0;
	string k;
	getline(cin,k) ;
	for(int i=0; i<k.size(); i++) {
		if(k[i]=='z')n++;
		else if(k[i]=='y') {
			a+=n*(n-1)/2;
		}
	}
	cout<<a<<endl;
	return 0;
}
