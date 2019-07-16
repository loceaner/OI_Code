#include<cstdio>
#include<cstring>
const int MAXN = 110;
int w[MAXN][MAXN];
int cnt[MAXN];
int ans,n,m,flag;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			w[i][j] = 1e7;
	for (int x,y,i=1; i<=m; ++i) {
		scanf("%d%d",&x,&y);
		w[y][x] = 1;
	}
	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				if (w[i][k]+w[k][j]<w[i][j])
					w[i][j] = w[i][k]+w[k][j];
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (w[i][j]<1e7) cnt[i]++, cnt[j]++;
	for (int i=1; i<=n; ++i)
		if (cnt[i]==n-1) ans++;
	printf("%d",ans);
	return 0;
}
