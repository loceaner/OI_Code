#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
using namespace std;
int x,y;
int main() {
	for(int i=1; i<=2; i++) {
		cin>>x>>y;
		if(x>2 || y>2)
			cout<<max(x/2,y/2)<<endl;
		else if((x==2 && y==1) || (x==1 && y==2))
			cout<<"2"<<endl;
		else cout<<"3"<<endl;
	}
	return 0;
}

