#include<cstdio>

const int maxn = 10005, maxm = 105;
const int mod = 20123;
int a[maxn][maxm];
bool b[maxn][maxm];
int cnt[maxn];//一层楼有多少个
int n, m, ans;

int read() {
	int ans = 0, s = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {
		if(ch == '-') s = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return s * ans;
}
int main() {
	//freopen("in.txt", "r", stdin);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			b[i][j] = read(), a[i][j] = read();
			if(b[i][j]) cnt[i]++;
		}
	}
	int now = read();
	for(int i = 1; i <= n; i++) {
		int num = a[i][now];
		ans = (ans + num) % mod;
		if(num % cnt[i] == 0) num = cnt[i];
		else num = num % cnt[i];
		while(num) {
			if(b[i][now]) {
				num--;
				if(num == 0) break;
			}
			now++;
			if(now >= m) now -= m;
		}
	}
	printf("%d\n", ans % mod);
	return 0;
}
