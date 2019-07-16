#include <bits/stdc++.h>
using namespace std;

int t, x, y;
int ans = 0x3f3f3f3f;

void dfs(int pos, int tot) {
	if(tot > ans) return;
	if(pos == y) {
		ans = min(tot, ans);
		return;
	}
	dfs(pos + 1, tot + 1);
	dfs(pos - 1, tot + 1);
	dfs(pos * 2, tot + 1);
}

int main() {
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d%d", &x, &y);
		dfs(x, 0);
		cout << ans << '\n';
	}
}
