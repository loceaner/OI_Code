#include<bits/stdc++.h>
#define MAXN 10010
using namespace std;

int n,m,pos,maxh;
int h[MAXN];

int main() {
	scanf("%d%d%d%d",&n,&pos,&maxh,&m);
	for(int i=1; i<=n; i++) {
		h[i]=maxh;
	} 
	for(int i=1; i<=m; i++) {
		int l,r;
		scanf("%d%d",&l,&r);
		if(l>r) swap(l,r);
		if(abs(l-r)!=1) {
			int maxn=-1;
			for(int j=l+1; j<r; j++)
				maxn=max(maxn,h[j]);
			if(maxn>=min(h[l],h[r]))
				for(int j=l+1; j<r; j++)
					h[j]-=1;
		}
	}
	for(int i=1; i<=n; i++)
		cout<<h[i]<<endl;
}
