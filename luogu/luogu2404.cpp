#include<bits/stdc++.h>
using namespace std;

int a[10086]= {1};
int n,total;
int search(int,int);
int print(int);

int main() {
	scanf("%d",&n);
	search(n,1);
	return 0;
}

int search(int s,int t) {
	for(int i=a[t-1]; i<=s; i++) {
		if(i<n) {
			a[t]=i;
			s-=i;
			if(s==0)print(t);
			else search(s,t+1);
			s+=i;
		}
	}
}

int print(int t) {
	for(int i=1; i<=t-1; i++) {
		cout<<a[i]<<"+";
	}
	cout<<a[t]<<endl;
}
