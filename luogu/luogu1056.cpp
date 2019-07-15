#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][1005];
struct nond {
	int k,rank;
} dd[2005],ff[2005];
int cmp(nond a,nond b) {
	return a.k>b.k;
}
int cmp2(nond a,nond b) {
	return a.rank<b.rank;
}
int main() {
	int m,n,k,l,d;
	cin>>m>>n>>k>>l>>d;
	for(int i=1; i<=d; i++) {
		int q,w,e,r;
		cin>>q>>w>>e>>r;
		if(q-e==0) {
			dd[min(w,r)].k++;
			dd[min(w,r)].rank=min(w,r);
		}
		if(w-r==0) {
			ff[min(q,e)].k++;
			ff[min(q,e)].rank=min(q,e);
		}
	}
	sort(dd+1,dd+2005,cmp);
	sort(ff+1,ff+2005,cmp);
	sort(dd+1,dd+l+1,cmp2);
	sort(ff+1,ff+k+1,cmp2);
	for(int i=1; i<=k; i++) {
		cout<<ff[i].rank<<' ';
	}
	cout<<endl;
	for(int i=1; i<=l; i++) {
		cout<<dd[i].rank<<' ';
	}
	return 0;
}
