#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;

inline int read() {
	char ch = getchar();
	int f = 1 , x = 0;
	while(ch > '9' || ch < '0') {
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int n,p,c[maxn],u[maxn],x,y,z;
int head[maxn],tot;
int in[maxn],out[maxn];
bool vis[maxn],flag;

struct Edge {
	int from,to,val,next;
} edge[maxn << 1];

void add(int u,int v,int w) {
	edge[++tot].from = u;
	edge[tot].to = v;
	edge[tot].val = w;
	edge[tot].next = head[u];
	head[u] = tot;
}

void dfs(int x) {
	for(int i=head[x]; i; i=edge[i].next) {
		int v = edge[i].to;
		c[v] += edge[i].val * c[x];
		in[v]--;
		if(!in[v] && c[v] - u[v] > 0) {
			c[v] -= u[v];
			dfs(v);
		}
	}
}

int main() {
	n = read();
	p = read();
	for(int i=1; i<=n; i++) {
		c[i] = read();
		u[i] = read();
		if(c[i] > 0)  vis[i] = true;
	}
	for(int i=1; i<=p; i++) {
		x = read();
		y = read();
		z = read();
		add(x , y , z);
		in[y]++;
		out[x]++;
	}
	for(int i=1; i<=n; i++)
		if(vis[i])  dfs(i);
	for(int i=1; i<=n; i++)
		if(out[i] == 0 && c[i] > 0) {
			printf("%d %d\n",i,c[i]);
			flag = true;
		}
	if(!flag)  printf("NULL\n");
	return 0;
}
