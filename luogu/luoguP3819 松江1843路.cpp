/*

1.��С�ĵ�һ���ǽ���ĳ�������ϡ�

2.����������ص㣡

3.�ҵ�����ͳ�ƴ𰸣�

4.����� 
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define N 100011
using namespace std;

inline ll read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

ll l, n, tot;

struct node {
	ll x, pep;
}a[N];

ll cmp(node a, node b) {return a.x < b.x;}

signed main() {
	l = read(), n = read();
	for(int i = 1; i <= n; i++) {
		a[i].x = read();
		a[i].pep = read();
		tot += a[i].pep;
	}
	tot = (tot + 1) / 2;
	stable_sort(a + 1, a + 1 + n, cmp);
	ll now = 0, mid = 0;
	for(int i = 1; i <= n; i++) {
		now += a[i].pep;
		if(now >= tot) {
			mid = i;
			break;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += a[i].pep * abs(a[mid].x - a[i].x);
	cout << ans << '\n';
	return 0;
}
