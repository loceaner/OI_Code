#include <algorithm>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node_map {
	int dis,next,to;
} map[55];

int n,m,a,b,c;
bool vis[55];
int head[55];
int ans,tot;

void add(int from,int to,int dis) {
	tot++;
	map[tot].to = to;
	map[tot].dis = dis;
	map[tot].next = head[from];
	head[from] = tot;
}

int DFS(int x) {
	if(vis[x]) return 0;
	vis[x] = 1;
	int ret = 0;
	for(int i=head[x]; i; i=map[i].next) {
		if(!vis[map[i].to])
			ret = max(ret,DFS(map[i].to)+map[i].dis);
	}
	vis[x] = 0;
	return ret;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1; i<=n; i++)
		if(!vis[i])
			ans = max(ans,DFS(i));
	printf("%d",ans);
	return 0;
}
