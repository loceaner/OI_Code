#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int n;
long long ans;
int a[5000007],b[5000007];

void sort(int l,int r) {
	if(l==r)return;
	int m=(l+r)>>1;
	sort(l,m);
	sort(m+1,r);
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r) {
		if(a[i]<=a[j])b[k++]=a[i++];
		else ans+=m-i+1,b[k++]=a[j++];
	}
	while(i<=m)b[k++]=a[i++];
	while(j<=r)b[k++]=a[j++];
	for(i=l; i<=r; ++i)a[i]=b[i];
}

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*w;
}

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		a[i]=read();
	}
	sort(1,n);
	printf("%lld",ans);
	return 0;
}
