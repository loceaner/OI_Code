#include <bits/stdc++.h>
#define N 45
using namespace std;

int bin[N][N][N][N];
int vis[N][N][N][N];
int w[400], p[5], n, m;

int dp(int a, int b, int c, int d) {
    if (a == 0 && b == 0 && c == 0 && d == 0)
        return w[1];
    if (vis[a][b][c][d])
        return bin[a][b][c][d];

    int now = a + 2 * b + 3 * c + 4 * d;

    if (a)
        bin[a][b][c][d] = max(bin[a][b][c][d], dp(a - 1, b, c, d));
    if (b)
        bin[a][b][c][d] = max(bin[a][b][c][d], dp(a, b - 1, c, d));
    if (c)
        bin[a][b][c][d] = max(bin[a][b][c][d], dp(a, b, c - 1, d));
    if (d)
        bin[a][b][c][d] = max(bin[a][b][c][d], dp(a, b, c, d - 1));

    bin[a][b][c][d] += w[1 + now];
    vis[a][b][c][d] = 1;
    return bin[a][b][c][d];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    int i;

    while (m--) {
        scanf("%d", &i);
        p[i]++;
    }

    bin[p[1]][p[2]][p[3]][p[4]] = 1;
    cout << dp(p[1], p[2], p[3], p[4]);

    return 0;
}
