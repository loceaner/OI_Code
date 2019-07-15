#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	int x,y,z,k=0,i;
	scanf("%d%d",&x,&y);
	if(y%x!=0) printf("%d\n",0);
	else {
		z=y/x;
		for(i=2; i<=z; ++i) { 
			if(z%i==0) {
				++k;
				while(z%i==0)z=z/i;
			}
		}
		printf("%d\n",int(pow(2,k)));
	}
	return 0;
}
