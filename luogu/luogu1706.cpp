#include<bits/stdc++.h>
using namespace std;

bool b[10086];
int a[10086];
int n,m;
long long tot;

void print() {
	for(int i=1; i<=n; i++) {
		cout<<setw(5)<<a[i];
	}
	cout<<endl;
}

int search(int t) {
	for(int i=1; i<=n; i++) {
		if(!b[i]) {
			a[t]=i;
			b[i]=1;
			if(t==n) {
				print();
			} else search(t+1);
			b[i]=0;
		}
	}
}


int main() {
	scanf("%d",&n);
	search(1);
	return 0;
}
