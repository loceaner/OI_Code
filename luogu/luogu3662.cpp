#include <bits/stdc++.h>
#define N 1000011
using namespace std;

int n, k, b;
int a[N];
int l, r;
int num;

int main() {
	scanf("%d%d%d", &n, &k, &b);
	for(int i = 1; i <= b; i++) {
		scanf("%d", &a[i]);
	}
	stable_sort(a + 1, a + b + 1);
	int ans = b, l = 0, r = 1;
	while(r <= b) {
		if(a[r] - a[l] - 1 >= k) ans = min(ans, num), l++, num--;
		else r++, num++;
	}
	cout << ans << '\n';
	return 0;
}
