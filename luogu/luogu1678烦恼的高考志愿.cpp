#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005],b[100005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<m; i++) scanf("%d",&b[i]);
	sort(a,a+n);
	int tot=0;
	for(int i=0; i<m; i++) {
		int zuo=0,you=n-1,ans=0x7fffffff,now=0;
		while(zuo<=you) {
			int c=(zuo+you)/2;
			if(a[c]<b[i]) {
				ans=min(ans,abs(b[i]-a[c]));
				zuo=c+1;
			} else {
				you=c-1;
				ans=min(ans,abs(b[i]-a[c]));
			}
		}
		tot+=ans;
	}
	printf("%d",tot);
}
