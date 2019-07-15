#include<bits/stdc++.h>
using namespace std;

int a[10];
int b;
int c=0;

int main() {
	for(int i=0; i<10; i++) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&b);
	for(int n=0; n<10; n++) {
		if(a[n]<=(b+30)) {
			c++;
		}
	}
	printf("%d",c);
	return 0;
}
