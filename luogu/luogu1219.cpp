#include<bits/stdc++.h>
using namespace std;

bool b[111],c[117],d[117];
int a[111],num=0;
int n;
int ans;

int print() {
	num++;
	if(num<=3) {
		for(int i=1; i<=n; i++) {
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
}

int search(int i) {
	for(int j=1; j<=n; j++) {
		if(!b[j] && !c[i+j] && !d[i-j+n]) {
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i-j+n]=1;
			if(i==n)print();
			else search(i+1);
			b[j]=0;
			c[i+j]=0;
			d[i-j+n]=0;
		}
	}
}

int main() {
	scanf("%d",&n);
	search(1);
	cout<<num;
	return 0;
}
