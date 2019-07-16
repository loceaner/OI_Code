#include<bits/stdc++.h>
using namespace std;
int main() {
	int r,b,c,d,e;
	scanf("%d%d%d%d%d",&r,&b,&c,&d,&e);
	int ans=0;
	ans+=r*c+b*d;
	if(2*e>c+d) {
		int minn=min(r, b);
		ans+=minn*(2*e-c-d);
	}
	printf("%d\n", ans);
	return 0;
}
