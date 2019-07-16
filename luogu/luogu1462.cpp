/*问题可以看作：
给定一张图，给定边权和点权，给定一个最大边权，
问，从点1到点n的路径的总长度不大于最大边权时点权的最大值最小
假设一个最大值，问题就变成了
　　求出一条经过的点的点权都不大于这个最大值的最短路径，并且这条最短路的长度小于最大边权（生命值为0就GG了）
好像可以二分答案，证一证它的单调性：
当一个数num被选为最大值的时候，如果存在一条
“经过的点的点权都不大于这个最大值的最短路径，并且这条最短路的长度小于最大边权”
则num可以选为最大值。
当num变小时，可以经过的城市变少，可选的点数变少，受到的伤害便可能增多，
使受到的伤害尽可能大（但不能超过总生命值），最大的点权值就会尽可能小，
　　故num不一定是最优解，所以从[l, mid]内寻找解
　　当num作为最大值过小时，就要从[mid + 1, r]中寻找解.
也就是说这道题将伤害视作边权，二分点权最大值，跑最短路松弛的条件多加了一个：松弛的点的点权必须小于最大点权
每次跑完最短路后如果受到的伤害小于血量那么这个最大点权便是一个解.*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 10000 + 1;
const int MAXM = 50000 + 1;
const int INF = 0x3f3f3f3f;

int n, m, blood;
int city[MAXN];

int edge_num, head[MAXN];
struct edge {
	int len, to, next;
} h[MAXM * 2];

inline void Add(int from, int to, int len) {
	h[++edge_num].next = head[from];
	h[edge_num].to = to, h[edge_num].len = len;
	head[from] = edge_num;
}

inline int read() {
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
		x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
	return x;
}

int fro, rear;
int dis[MAXN], que[MAXN * 20];
bool in_que[MAXN];
void SPFA(int money) {
	for(int i = 0; i <= n; i++) dis[i] = INF;
	memset(in_que, 0, sizeof(in_que));
	in_que[1] = 1, dis[1] = 0;
	que[fro = rear = 1] = 1;
	while(fro <= rear) {
		int x = que[fro++];
		in_que[x] = 0;
		for(int i = head[x]; i; i = h[i].next) {
			int l = h[i].len, y = h[i].to;
			if(dis[x] + l < dis[y] && city[y] <= money) {
				dis[y] = dis[x] + l;
				if(!in_que[y]) in_que[y] = 1, que[++rear] =y;
			}
		}
	}
}

inline bool check(int money) {
	SPFA(money);
	return dis[n] < blood;
}
int main() {
	int l = 0, r = 0;
	n = read(), m = read(), blood = read();
	for(int i = 1; i <= n; ++i) {
		city[i] = read();
		r = max(r, city[i]);
	}
	l = max(city[1], city[n]);
	for(int i = 1; i <= m; ++i) {
		int a, b, c;
		a = read(), b = read(), c = read();
		if(a != b) {
			Add(a, b, c);
			Add(b, a, c);
		}
	}
	if(!check(r)) {
		puts("AFK");
		return 0;
	}
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(!check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", l);
}
