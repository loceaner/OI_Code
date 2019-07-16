/*������Կ�����
����һ��ͼ��������Ȩ�͵�Ȩ������һ������Ȩ��
�ʣ��ӵ�1����n��·�����ܳ��Ȳ���������Ȩʱ��Ȩ�����ֵ��С
����һ�����ֵ������ͱ����
�������һ�������ĵ�ĵ�Ȩ��������������ֵ�����·���������������·�ĳ���С������Ȩ������ֵΪ0��GG�ˣ�
������Զ��ִ𰸣�֤һ֤���ĵ����ԣ�
��һ����num��ѡΪ���ֵ��ʱ���������һ��
�������ĵ�ĵ�Ȩ��������������ֵ�����·���������������·�ĳ���С������Ȩ��
��num����ѡΪ���ֵ��
��num��Сʱ�����Ծ����ĳ��б��٣���ѡ�ĵ������٣��ܵ����˺���������࣬
ʹ�ܵ����˺������ܴ󣨵����ܳ���������ֵ�������ĵ�Ȩֵ�ͻᾡ����С��
������num��һ�������Ž⣬���Դ�[l, mid]��Ѱ�ҽ�
������num��Ϊ���ֵ��Сʱ����Ҫ��[mid + 1, r]��Ѱ�ҽ�.
Ҳ����˵����⽫�˺�������Ȩ�����ֵ�Ȩ���ֵ�������·�ɳڵ����������һ�����ɳڵĵ�ĵ�Ȩ����С������Ȩ
ÿ���������·������ܵ����˺�С��Ѫ����ô�������Ȩ����һ����.*/
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
