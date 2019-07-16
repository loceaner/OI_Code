#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1005;
int n, m, a[N], b[N], c[N], f[N];
vector<int> g[N];

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", a + i, b + i, c + i);
		g[c[i]].push_back(i);
	}
	for (int i = 1; i <= 100; ++i) {
		for (int k = m; k >= 0; --k) {
			for (int ii = 0; ii < g[i].size(); ++ii) {
				int j = g[i][ii];
				if (k - a[j] >= 0) {
					f[k] = max(f[k], f[k - a[j]] + b[j]);
				}
			}
		}
	}
	printf("%d\n", f[m]);
}

