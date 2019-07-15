#include <cstdio>
#include <iostream>
using namespace std;

int n, maxv, maxw;
int f[410][410];

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

inline int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int i, j, k, v, w, val;
	maxv = read();
	maxw = read();
	n = read();
	for(i = 1; i <= n; i++) {
		v = read();
		w = read();
		val = read();
		for(j = maxv; j >= v; j--)
			for(k = maxw; k >= w; k--)
				f[j][k] = max(f[j][k], f[j - v][k - w] + val);
	}
	printf("%d\n", f[maxv][maxw]);
	return 0;
}
