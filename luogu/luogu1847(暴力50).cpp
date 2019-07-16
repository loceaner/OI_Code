#include <iostream>
#include <cstdio>
#define N 1011
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int m, n;
int x1, y1, x2, y2;
int x, y;
int last[N][N],a[N][N];

int main() {
	m = read(), n = read();
	for(int i = 1; i <= m; i++) {
		x1 = read(), y1 = read(), x2 = read(), y2 = read();
		for(int j = x1; j <= x2; j++){
			for(int k = y1; k <= y2; k++){
				a[j][k] = 1;
				last[j][k] = i;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		x = read(), y = read();
		if(a[x][y]){
			cout<<"YES ";
			cout<< last[x][y] <<'\n';
		}
		else cout<<"NO\n";
	}
}
