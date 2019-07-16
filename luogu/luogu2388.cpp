#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans = 0, m = 0;

signed main() {
	int n, t;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		t = i;
		while(t%5 == 0) {
			m++;
			t /= 5;
		}
		ans += m;
	}
	cout << ans << '\n';
	return 0;
}
