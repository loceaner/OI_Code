#include <bits/stdc++.h>
#define N 10000011
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return x * f;
}

int n, m, t, p;
int group[N];
queue <int> q,last[311];


int main() {
	n = read(), m = read();
	for(int i = 0; i < n; i++) {
		group[i] = read();
	}
	t = read();
	for(int i = 1; i <= t; i++) {
		string s;
		cin >> s;
		if(s == "push") {
			p = read();
			if(last[group[p]].empty())
				q.push(group[p]);
			last[group[p]].push(p);
		} else {
			cout << last[q.front()].front() << '\n';
			last[q.front()].pop();
			if(last[q.front()].empty())
				q.pop();
		}
	}
	return 0;
}
