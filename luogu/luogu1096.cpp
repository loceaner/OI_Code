#include <bits/stdc++.h>
using namespace std;

int n, num[211], len;
int x = 0;

void cheng() {
	for(int i = 1; i <= n; i++) {
		num[i] = (num[i]<<1) + x;
		if(num[i] > 9) {
			x = num[i] / 10;
			num[i] %= 10;
			len = max(len, i + 1);
		} else x = 0;
	}
}

int main() {
	scanf("%d", &n);
	len = 1;
	num[1] = 1;
	for(int i = 1; i <= n; i++) cheng();
	num[1] -= 1;
	for(int i = 1; i <= len; i++) {
		if(num[i] < 0) {
			num[i]++;
			num[i + 1]--;
		}
	}
	cheng();
	for(int i = len; i; i--) cout << num[i];
	return 0;
}
