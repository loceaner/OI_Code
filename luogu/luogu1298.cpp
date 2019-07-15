#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<list>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<queue>
#include<set>
using namespace std;
int main() {
	double xs,cha=10.0,f;
	int m,zi,mu,n,ans=-1,js;
	scanf("%d%d",&n,&m);
	scanf("%lf",&xs);
	for(int i=1; i<=m; i++) {
		js=xs*i;
		if (js>n) break;
		f=(double)js/(double)i;
		if (i==1) {
			ans=1;
			cha=xs-f;
			zi=js;
			mu=i;
		} else if (zi*i!=mu*js) {
			if(xs-f==cha)ans++;
			if(xs-f<cha) {
				ans=1;
				cha=xs-f;
				zi=js;
				mu=i;
			}
		}
		js++;
		if (zi*i!=mu*js&&js<=n) {
			f=(double)js/(double)i;
			if (f-xs==cha) ans++;
			if (f-xs<cha) {
				ans=1;
				cha=f-xs;
				zi=js;
				mu=i;
			}
		}
	}
	if (ans>1) printf("TOO MANY\n");
	else if (ans==-1) printf("%d/1\n",n);
	else printf("%d/%d\n",zi,mu);
	return 0;
}
