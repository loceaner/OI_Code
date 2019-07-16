#include<bits/stdc++.h>
#define N 10010
using namespace std;

int n,T;
int m,w;
double c[N],b[N];

struct node {
	int sex;
	double gao;
} a[N];

bool comp(node x,node y) {
	return x.gao<y.gao;
}

int main() {
	cin>>T;//scanf("%d",&T);
	for(int e=1;e<=T;e++) {
		w=0,m=0;
		cin>>n;//scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			cin>>a[i].sex;
		}
		for(int i=1; i<=n; i++) {
			cin>>a[i].gao;
		}
		sort(a+1,a+1+n,comp);
		for(int i=1; i<=n; i++) {
			if(a[i].sex==0){
				c[++m]=a[i].gao;
			}
			else b[++w]=a[i].gao;
		}
		for(int i=1; i<=m; i++) {
			cout<<c[i]<<" ";
		}
		cout<<'\n';
		for(int i=1; i<=w; i++) {
			cout<<b[i]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
