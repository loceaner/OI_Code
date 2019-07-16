#include <iostream> 
#include <cstdio>

inline void read(int &x) {//¿ì¶Á 
	x=0;
	register char ch=getchar();
	for(; ch>'9'||ch<'0'; ) ch=getchar();
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-'0';
}

const int N(2333);

int n,m;

struct Node {
	int x1,x2,y1,y2;
} a[N];

inline void Work(int x,int y) {
	int pos,cnt=0;
	for(int i=1; i<=m; ++i)
		if(a[i].x1<=x&&a[i].x2>=x&&a[i].y1<=y&&a[i].y2>=y)
			cnt++,pos=i;
	if(!cnt) puts("NO");
	else printf("YES %d %d\n",cnt,pos);
}

int Presist() {
	read(m),read(n);
	for(int i=1; i<=m; ++i)
		read(a[i].x1),read(a[i].y1),
		     read(a[i].x2),read(a[i].y2);
	for(int x,y,i=1; i<=n; ++i)
		read(x),read(y),Work(x,y);
	return 0;
}

int Aptal=Presist();
int main(int argc,char**argv) {
	;
}
