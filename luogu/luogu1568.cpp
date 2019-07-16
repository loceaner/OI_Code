#include<iostream>
#include<cstdio>
using namespace std;

int n,m,wn,wm,vn[1001],tn[1001],vm[1001],tm[1001];
int nt=1,mt=1,z=-1,ans=-1;

int work(int x) {
	if(x>0)
		return 1;
	else if(x==0)
		return z;
	return 0;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&vn[i],&tn[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&vm[i],&tm[i]);
		while(mt<=i) {
			if(tm[mt]==0 && mt<=m+1) {
				mt++;
				continue;
			}
			if(tn[nt]==0 && nt<=n+1) {
				nt++;
			}
			wm+=vm[mt];
			tm[mt]--;
			wn+=vn[nt];
			tn[nt]--;
			int s=wm-wn;
			if(work(s)!=z) {
				ans++;
				z=work(s);
			}
		}
	}
	if(ans==-1)ans=0;
	printf("%d",ans);
}
