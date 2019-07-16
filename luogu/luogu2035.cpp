#include"bits/stdc++.h"
#define N 1011
using namespace std;

int n,t;
int now;

struct edge {
	int r;
	int num;
} a[N];

inline int read() {
	int x=0,f=1;
	char c=getchar();
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-1;
	for(;  isdigit(c); c=getchar()) x=x*10+c-'0';
	return x*f;
}

inline int cmp(edge x,edge y) {
	return x.r==y.r ? x.num<y.num : x.r>y.r;
}

inline int cmd(edge x,edge y) {
	return x.num<y.num;
}

int main(void) {
	n=read();
	t=read();
	for(int i=1; i<=n; ++i) {
		a[i].r=read();
		a[i].num=i;
	}
	int cnt=0;
	sort(a+1,a+1+n,cmp);
	while(cnt!=t) {
		now=a[1].num;
		for(int i=2; i<=n; i++) {
			a[i].r+=a[1].r/(n-1);
		}
		if(a[1].r%(n-1)!=0) {
			int opt=a[1].r%(n-1);
			a[1].r=0;
			sort(a+1,a+1+n,cmd);;
			for(int i=1; i<=n; i++) {
				if(a[i].num==now)continue;
				opt--,a[i].r++;
				if(opt==0)break;
			}
		} else a[1].r=0;
		sort(a+1,a+1+n,cmp);
		cout<<now<<'\n';
		cnt++;
	}
	return 0;
}
