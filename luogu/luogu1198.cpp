#include <bits/stdc++.h>
#define N 1000011
using namespace std;

int n, x, d, cnt, t;
int maxn[N];
char c;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

inline void pushup(int rt) {
	maxn[rt] = max(maxn[rt << 1], maxn[rt << 1 | 1]);
}

void update(int L, int c, int l, int r, int rt) {
	if(l == r) {
		maxn[rt] = c;
		return;
	}
	int m = (l + r) >> 1;
	if(L <= m) update(L, c, l, m, rt << 1);
	else update(L, c, m + 1, r, rt << 1 | 1);
	pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= r) return maxn[rt];
	int m = (l + r) >> 1, ans = -0x7fffffff;
	if(L <= m) ans = max(ans, query(L, R, l, m, rt << 1));
	if(R > m) ans = max(ans, query(L, R, m + 1, r, rt << 1 | 1));
	return ans;
}

int main() {
	n = read(), d = read();
	for(int i = 1; i <= n; i++) {
		cin >> c;
		x = read();
		if (c == 'A') {
			cnt ++;
			update(cnt, (x + t) % d, 1, n, 1);
		} else t = query(cnt - x + 1, cnt, 1, n, 1) % d, printf("%d\n", t);
	}
	return 0;
}
