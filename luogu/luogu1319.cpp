#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int x,i=0,m,t=0,s=0;//i�ж����0����1��s�ж���û�����꣬t�жϻس� 
	cin>>x;
	while(s<x*x) {
		cin>>m;
		i++;
		for(int b=m; b>=1; b--) {
			if(t==x) {
				cout<<endl;
				t=0;
			}
			if(i%2==1)cout<<0;
			else cout<<1;
			t++;
			s++;
		}
	}
}
