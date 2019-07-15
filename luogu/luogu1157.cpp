#include<bits/stdc++.h>
using namespace std;

bool b[10086];
int a[10086];
int n,m;
long long tot;

void print() {
	for(int i=1; i<=m; i++) {
		cout<<setw(3)<<a[i];
	}
	cout<<endl;
}

int search(int t) {
	for(int i=1; i<=n; i++) {
		if(!b[i]&& i>a[t-1]) {
			a[t]=i;
			b[i]=1;
			if(t==m) {
				print();
			} else search(t+1);
			b[i]=0;
		}
	}
}


int main() {
	scanf("%d%d",&n,&m);
	search(1);
	return 0;
}
