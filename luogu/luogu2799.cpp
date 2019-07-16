#include<bits/stdc++.h>
using namespace std;

char s[1000101];

void dg(int a){
	int mid=a/2;
	if(a%2==1){
		cout<<a;
		return;
	}
	else{
		for(int i=0,j=a-1;i<mid;i++,j--){
			if(s[i]!=s[j]){
				cout<<a;
				return;
			}
		}
	}
	dg(mid);
}

int main(){
	gets(s);
	char t;
	int len=strlen(s);
	dg(len);
	return 0;
}
