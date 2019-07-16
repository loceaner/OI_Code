#include<bits/stdc++.h>
using namespace std;
int a[100000+5],b[100000+5],c[100000+5],d[2000000+5],ans,asf;
int main() {
	int a1,a2,a3;
	cin>>a1>>a2>>a3;
	for(int i=1; i<=a1; i++) {
		a[i]=i;
	}
	for(int i=1; i<=a2; i++) {
		b[i]=i;
	}
	for(int i=1; i<=a3; i++) {
		c[i]=i;
	}
	for(int i=1; i<=a1; i++) {
		for(int j=1; j<=a2; j++) {
			for(int k=1; k<=a3; k++) {
				int qwe;
				qwe=a[i]+b[j]+c[k];
				d[qwe]++;
			}
		}
	}
	for(int i=1; i<=200000+5; i++) {
		if(d[i]>ans) {
			ans=d[i];
			asf=i;
		}
	}
	cout<<asf;
	return 0;
}
