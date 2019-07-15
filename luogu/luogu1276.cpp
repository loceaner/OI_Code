#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100011
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

struct node {
	int l, r, sta;
} tr[N];

int l, n, a1, a2;

void build(int p) {
	if(tr[p].l == tr[p].r) {
		tr[p].sta = 1;
		return;
	}
	int mid = (tr[p].l + tr[p].r) >> 1;
	tr[p * 2].l = tr[p].l;
	tr[p * 2].r = mid;
	tr[p * 2 + 1].l = mid + 1;
	tr[p * 2 + 1].r = tr[p].r;
	tr[p * 2].sta = tr[p * 2 + 1].sta = 1;
	build(p * 2);
	build(p * 2 + 1);
}

void cut(int p, int x, int y) {
	if(tr[p].sta != -1) tr[p * 2].sta = tr[p * 2 + 1].sta = tr[p].sta;
	if(tr[p].sta == 0) return;
	if(tr[p].l == x && tr[p].r == y && tr[p].sta != -1) {
		if(tr[p].sta == 2) {
			a2 += tr[p].r - tr[p].l + 1;
			a1 -= tr[p].r - tr[p].l + 1;
		}
		tr[p].sta = 0;
		return;
	}
	int mid = (tr[p].l + tr[p].r)/2;
	if(y <= mid) cut(p * 2, x, y);
	else if(x > mid) cut(p * 2 + 1, mid + 1, y);
	else cut(p * 2, x, mid), cut(p * 2 + 1, mid + 1, y);
	if(tr[p * 2].sta != tr[p * 2 + 1].sta) tr[p].sta = -1;
	else tr[p].sta = tr[p * 2].sta;
}

void plant(int p, int y, int x) {
	if(tr[p].sta != -1) tr[p * 2].sta = tr[p * 2 + 1].sta = tr[p].sta;
	if(tr[p].sta == 1 || tr[p].sta == 2) return;
	if(tr[p].l == x && tr[p].r == y && tr[p].sta != -1) {
		tr[p].sta = 2;
		a1 += tr[p].r - tr[p].l + 1;
		return;
	}
	int mid = (tr[p].l + tr[p].r)/2;
	if(y <= mid) plant(p * 2, x, y);
	else if(x > mid) plant(p * 2 + 1, mid + 1, y);
	else plant(p * 2, x, mid), plant(p * 2 + 1, mid + 1, y);
	if(tr[p * 2].sta != tr[p * 2 + 1].sta) tr[p].sta = -1;
	else tr[p].sta = tr[p * 2].sta;
}

int main() {
	l = read(), n = read();
	tr[1].l = 0;
	tr[1].r = l;
	tr[1].sta = 1;
	build(1);
	for(int i = 1; i <= n; i++){
		int z = read(), x = read(), y = read();
		if(z == 1) plant(1, x, y);
		else cut(1, x, y);
	}
	cout<< a1 << '\n' << a2;
	return 0; 
}
