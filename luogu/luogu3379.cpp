#include <bits/stdc++.h>
#define N 500011
using namespace std;

struct node {
	int to, ne;
}e[N << 1];

int n, m, s, cnt, head[N], d[N], siz[N], son[N], top[N], f[N];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

void add(int x, int y) {
	e[++cnt].to = y;
	e[cnt].ne = head[x];
	head[x] = cnt; 
}

void dfs1(int now) {
	siz[now] = 1;
	d[now] = d[f[now]] + 1;
	for(int i = head[now]; i; i = e[i].ne) {
		int dd = e[i].to;
		if(dd == f[now]) continue;
		f[dd] = now;
		dfs1(dd);
		siz[now] += siz[dd];
		if(!son[now] || siz[son[now]] < siz[dd]) son[now] = dd;
	}
}

void dfs2(int now, int tv) {
	top[now] = tv;
	if(son[now]) dfs2(son[now], tv);
	for(int i = head[now]; i; i = e[i].ne) {
		int dd = e[i].to;
		if(dd == f[now] || dd == son[now]) continue;
		dfs2(dd, dd);
	}
}

int main() {
	n = read(), m = read(), s = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y);
		add(y, x);
	}
	dfs1(s);
	dfs2(s, s);
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		while(top[x] != top[y]) {
			if(d[top[x]] >= d[top[y]]) x = f[top[x]];
			else y = f[top[y]];
		}
		cout << (d[x] < d[y] ? x : y) << '\n';
	}
	return 0;
}
/*
���ʾ��ǰ����ʷֳ����������ཻ������Ŀǰ�����������ʳ�������

�������Ƕ���siz[x]Ϊ��xΪ�����������Ľ�����

����ÿ�����x�������������ӽ����Ѱ��һ�����y

ʹ�ö���y���ֵܽڵ�z������siz[y]��siz[z]

��ʱx����һ���ر�����y��������������������������ӽ�㡾����z��

�����Ļ������ϵĲ��������ϵıߵ������ͻ������

Ȼ������ÿ����LCA��x,y����ʱ��Ϳ����ж������Ƿ���ͬһ����

���������ͬһ����������ֻҪ�ҵ�����������Ƚ�С�ĵ����������

������㲻��ͬһ������

�Ǿ��ҵ���Ƚϴ�ĵ��������������ڵ��������˵ĸ��ڵ㼴Ϊx=f[top[x]]

ֱ�����㵽��ͬһ�����ϣ������������Ƚ�С�ĵ�
*/
