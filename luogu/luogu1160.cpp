#include <bits/stdc++.h>
#define N 100011
using namespace std;

bool f[N];
int to[N], n, fm[N], m;

int main() {
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int k, p;
		scanf("%d%d", &k, &p);
		if(p == 0) {
			to[i] = k;
			to[fm[k]] = i;
			fm[i] = fm[k];
			fm[k] = i;
		}
		if(p == 1) {
			to[i] = to[k];
			fm[i] = k;
			fm[to[k]] = i;
			to[k] = i;
		}
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		if(!f[x]) {
			to[fm[x]] = to[x];
			fm[to[x]] = fm[x];
			f[x]= true;
		}
	}
	int k;
	for(int i = 1; i <= n; i++) {
		if(fm[i] == 0) k = i;
	}
	cout << k << ' ';
	while(to[k] != 0) {
		k = to[k];
		cout << k << ' '; 
	}
	return 0;
}
