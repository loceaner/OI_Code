#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int flower[25][25];

struct node {
	int x, y;
	int num;
} nuts[405];

int cmp(node a,node b) {
	return a.num > b.num;
}
int index=1;
int main() {
	int M, N, K;
	cin >> M >> N >> K;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			cin >> flower[i][j];
			if (flower[i][j])
				nuts[index].num = flower[i][j], nuts[index].x = i, nuts[index].y = j, index++;
		}

	sort(nuts+1, nuts + index, cmp);
	int tmp;
	int dist;
	int total = 0;
	for (int i = 1; i <= index; i++) {
		if (i == 1)
			dist = nuts[i].x;
		else
			dist = abs(nuts[i - 1].x - nuts[i].x) + abs(nuts[i - 1].y - nuts[i].y);
		tmp = K - dist - 1;
		if (tmp >= nuts[i].x) {
			total += nuts[i].num;
			K = K - dist - 1;
		} else
			break;
	}
	cout << total;
	return 0;
}
