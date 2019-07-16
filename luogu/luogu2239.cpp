#include<bits/stdc++.h>
#define R register
using namespace std;
inline void in(int &x) {
	int f=1;
	x=0;
	char s=getchar();
	while(!isdigit(s)) {
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)) {
		x=x*10+s-'0';
		s=getchar();
	}
	x*=f;
}
int n,x,y,ans;
int main() {
	in(n),in(x),in(y);
here:
	;
	if(x==1)printf("%d",y+ans);
	else if(y==n)printf("%d",n+x-1+ans);
	else if(x==n)printf("%d",3*n-y-1+ans);
	else if(y==1)printf("%d",4*n-x-2+ans);
	else {
		ans+=4*n-4;
		x--,y--,n-=2;
		goto here;
	}
}
