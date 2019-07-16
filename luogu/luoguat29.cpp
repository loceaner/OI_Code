#include <bits/stdc++.h>
#define N 1000011
using namespace std;

int a[N], b[N];
int n;
int ans = 0;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c) ; c = getchar()) if (c == '-' )f = -1;
	for(; isdigit(c) ; c = getchar()) x = (x << 3) + (x << 1) + c - 48;
	return x * f;
}

int main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = read();
		if(a[i] < b[i]) ans++;
	}
	cout << ans << '\n';
	return 0;
}
