#include <bits/stdc++.h>
#define N 100011
#define lowbit(x) (x&(-x))
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

struct node {
	int x, num;
}a[N];

bool cmp(const node &a, const node &b){
	return a.x < b.x || (a.x == b.x && a.num <b.num);
}

int n, ans, sum[N];

void update(int x){
	for(int i = x; i <= N; i += lowbit(i)){
		sum[i]++;
	}
}

int query(int x){
	int ans = 0;
	for(int i = x; i; i -= lowbit(i)) ans += sum[i];
	return ans;
}

signed main() {
	n = read();
	for(int i = 1; i <= n; i++){
		a[i].x = read();
		a[i].num = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		update(a[i].num);
		ans = max(ans, i - query(i));
	}
	cout << max(ans, 1);
	return 0;
}
