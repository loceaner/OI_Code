#include<cstdio>
#include<cstring>
#include<queue>
const int maxn = 105;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
struct Nodes {
	int x, y, col;
	Nodes(int x, int y, int col):x(x), y(y), col(col) {}
};
int G[maxn][maxn];
int dist[maxn][maxn][2];
bool vis[maxn][maxn][2];
int n, m;

int main() {
	memset(dist, 0x3f, sizeof dist);
	memset(G, -1, sizeof G);
	scanf("%d%d", &n, &m);
	while(m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		G[x][y] = z;
	}
	std::queue<Nodes> q;
	dist[1][1][G[1][1]] = 0;
	q.push(Nodes(1, 1, G[1][1]));
	vis[1][1][G[1][1]] = true;
	while(!q.empty()) {
		Nodes u = q.front();
		q.pop();
		int x = u.x, y = u.y, col = u.col, res = dist[x][y][col];
		vis[x][y][col] = false;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if(G[nx][ny] == -1) {
					if(G[x][y] == -1) continue;
					if(res + 2 < dist[nx][ny][col]) {
						dist[nx][ny][col] = res + 2;
						if(!vis[nx][ny][col]) {
							q.push(Nodes(nx, ny, col));
							vis[nx][ny][col] = true;
						}
					}
				} else if(G[nx][ny] != col) {
					if(res + 1 < dist[nx][ny][G[nx][ny]]) {
						dist[nx][ny][G[nx][ny]] = res + 1;
						if(!vis[nx][ny][G[nx][ny]]) {
							q.push(Nodes(nx, ny, G[nx][ny]));
							vis[nx][ny][G[nx][ny]] = true;
						}
					}
				} else if(G[nx][ny] == col) {
					if(res < dist[nx][ny][G[nx][ny]]) {
						dist[nx][ny][G[nx][ny]] = res;
						if(!vis[nx][ny][G[nx][ny]]) {
							q.push(Nodes(nx, ny, G[nx][ny]));
							vis[nx][ny][G[nx][ny]] = true;
						}
					}
				}
			}
		}
	}
	int ans;
	if(G[n][n] != -1) ans = dist[n][n][G[n][n]];
	else ans = std::min(dist[n][n][0], dist[n][n][1]);
	if(ans != 0x3f3f3f3f) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}
