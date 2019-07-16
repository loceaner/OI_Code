#include<cmath>
#include<cstdio>
#include<algorithm>
int n,a,b,c,ans=2100000000,x;
int main() {
	scanf("%d",&n);
	for (int i=1; i<=3; i++) {
		scanf("%d%d",&a,&b);
		x=std::ceil(n*1.0/a)*b;
		ans=std::min(x,ans);
	}
	printf("%d\n",ans);
	return 0;
}
