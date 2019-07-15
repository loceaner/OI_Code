#include <bits/stdc++.h>
#define N 100011
using namespace std;

int n, x1, y11, x2, y2, now1, now2, minn;

struct node {
	int x, y, dis1, dis2;
} d[N];

bool cmp(node x, node y) {
	return x.dis1 > y.dis1;
}

int jl(int x, int y, int k) {
	if(k == 1) return (x - x1) * (x - x1) + (y - y11) * (y - y11);
	else return (x - x2) * (x - x2) + (y - y2) * (y - y2);
}

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int main() {
	x1 = read(), y11 = read(), x2 = read(), y2 = read();
	n = read();
	for(int i = 1; i <= n; i++) {
		d[i].x = read(), d[i].y = read();
		d[i].dis1 = jl(d[i].x, d[i].y, 1);
		d[i].dis2 = jl(d[i].x, d[i].y, 2);
	}
	sort(d + 1, d + 1 + n, cmp);
	now1 = d[1].dis1;
	minn = d[1].dis1;
	int js = 0;
	for(int i = 1; i <= n; i++){
		now1 = d[i + 1].dis1;
		if(now2 < d[i].dis2) now2 = d[i].dis2;
		js = now1 + now2;
		if(js < minn) minn = js;
	}
	cout << minn << '\n';
	return 0;
}
