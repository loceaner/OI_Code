#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> >que;
int a[2010];
int n, ans=1000000000;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		a[n + i] = a[i];
	}
	for(int i = 1; i <= n; i++) {
		int flag=0, cnt=0;
		for(int j = i; j <= i + n - 1; j++) {
			if(a[j] == 0 && que.size() == 0) {
				flag = 1;
				break;
			}
			int x = a[j];
			while(x) {
				que.push(j);
				x--;
			}
			int now = que.top();
			que.pop();
			cnt += (j - now) * (j - now);
		}
		if(flag == 1) continue;
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}
