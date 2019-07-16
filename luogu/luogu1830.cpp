#include <iostream>
#include <cstdio>
#define N 2111
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

struct node {
	int llx, lly;
	int rrx, rry;
} ju[N];

int m, n, x, y;

int main() {
	n = read(), m = read(), x = read(), y = read();
	for(int i = 1; i <= x; i++) {
		ju[i].llx = read();
		ju[i].lly = read();
		ju[i].rrx = read();
		ju[i].rry = read();
	}
	int p, q;
	for(int i = 1; i <= y; i++) {
		p = read(), q = read();
		int ans = 0, pos;
		for(int j = 1; j <= x; j++) {
			if(p >= ju[j].llx && p <= ju[j].rrx && q >= ju[j].lly && q <= ju[j].rry) {
				ans++;
				pos = j;
			}
		}
		if(ans == 0) {
			cout << "N\n";
		} else {
			cout << "Y " << ans <<" "<< pos <<'\n';
		}
	}
	return 0;
}
