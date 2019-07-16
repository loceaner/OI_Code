#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<set>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

#define inf 0x7f7f7f7f
using namespace std;
typedef long long LL;
typedef pair<int, int> pr;

int n;
struct node {
	double x, y;
} pos[20];
int per[20];
double d[20][20];

double dist(node a, node b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(int a, int b) {
	return a > b;
}

bool vis[20];
double ans = inf;
void dfs(int pre, int m, double res) {
	if(res > ans)return;
	if(m == n) {
		ans = min(ans, res);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = true;
			dfs(i, m + 1, res + d[pre][i]);
			vis[i] = false;
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	pos[0].x = 0;
	pos[0].y = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lf%lf", &pos[i].x, &pos[i].y);
		per[i] = i;
	}
	for(int i = 0; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			d[i][j] = d[j][i] = dist(pos[i], pos[j]);
		}
	}
	dfs(0, 0, 0);
	printf("%.2lf\n", ans);
	return 0;
}
