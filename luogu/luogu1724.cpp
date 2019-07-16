#include<cstdio>
#include<iostream>
#include<cstring>
#define N 200010
using namespace std;

struct node {
	int x;
	int y;
};
char b[N];
node a,d;

int main() {	
	int n,c=0,l,s=0;
	a.x=0,a.y=0;
	scanf("%s %d",b,&n);
	l=strlen(b);
	for(int i=0; i<l; i++) 
		switch(b[i]) {
			case 'E':a.x++;break;
			case 'S':a.y--;break;
			case 'W':a.x--;break;
			case 'N':a.y++;break;
		}
	d=a;
	for(int i=1; i<n/l; i++) { 
		a.x+=d.x;
		a.y+=d.y;
	}
	for(int i=0; i<n%l; i++)
		switch(b[i]) {
			case 'E':a.x++;break;
			case 'S':a.y--;break;
			case 'W':a.x--;break;
			case 'N':a.y++;break;
		}
	printf("%d %d",a.x,a.y);
	return 0;
}
