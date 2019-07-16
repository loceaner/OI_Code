#include<bits/stdc++.h>
using namespace std;
int n,xx0,xx1,yy0,yy1,ans;
struct node {
	int x,y,r;
} a[55];
int JS(int x,int y,node a) {
	if((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y)<=(a.r)*(a.r)) return 1;
	return 0;
}
int main() {
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i].x;
	for(int i=1; i<=n; ++i) cin>>a[i].y;
	for(int i=1; i<=n; ++i) cin>>a[i].r;
	cin>>xx0>>yy0>>xx1>>yy1;
	for(int i=1; i<=n; ++i)
		if(JS(xx0,yy0,a[i])^JS(xx1,yy1,a[i])) ans++;
	printf("%d\n",ans);
	return 0;
}
