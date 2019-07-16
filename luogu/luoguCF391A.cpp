#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

string a;
int ans=0,m=1;

int main() {
	cin>>a;
	for(int i=0; i<=a.length()-1; i++) {
		for(int j=i+1; j<=a.length(); j++) {
			if(a[j]==a[i]) {
				m++;
			} else {
				if(m%2==0)ans++;
				m=1;
				i=j;
			}
		}
	}
	cout<<ans;
}
