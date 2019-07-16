#include<cstdio>
#include<iostream>
using namespace std;
int b[1005]= {0},e[1005]= {0};
struct {
	int x1;
	int y1;
	int x2;
	int y2;
} a[1005];
int main() {
	int i,n,m,x,y,j,x1,y1,x2,y2,c,d;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i=0; i<x; i++)
		cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
	for(i=0; i<y; i++) {
		cin>>c>>d;
		for(j=0; j<x; j++)
			if(a[j].x1<=c&&a[j].y1<=d&&a[j].x2>=c&&a[j].y2>=d) {
				b[i]++;
				e[i]=j;
			}
	}
	for(i=0; i<y; i++)
		if(b[i]==0)
			cout<<"N"<<endl;
		else
			cout<<"Y "<<b[i]<<" "<<e[i]+1<<endl;
	return 0;
}
