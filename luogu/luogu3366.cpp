#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,k;
int ans=0;
int pre[5050];
struct point {
	int x,y,w;
} a[200010];

int find(int x) {
	if(pre[x]==x)return x;
	else {
		pre[x]=find(pre[x]);
		return pre[x];
	}
}

bool cmp(point a,point b) {
	return a.w<b.w;
}

void init(){
	for(int i=1;i<=n;i++)
	pre[i]=i;
}

int main() {
	scanf("%d%d",&n,&m);
	init();
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1; i<=m; i++) {
  		if(find(a[i].x)!=find(a[i].y)) {
			pre[find(a[i].x)]=find(a[i].y);
			ans+=a[i].w;
			k++;
		}
		if(k==n-1)break;
	}
	cout<<ans<<'\n';
	return 0;
}
