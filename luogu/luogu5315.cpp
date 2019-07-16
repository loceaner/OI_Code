#include<bits/stdc++.h>
using namespace std;
int n,l,g;
void judge(int w,int h) {
	if(l>min(w,h)) {
		puts("Too Young");
		return;
	}
	if(g>=max(w,h)) {
		puts(w==h?"Sometimes Naive":"Too Simple");
		return;
	}
	judge(w>>1,h>>1);
}
int main() {
	scanf("%d%d%d",&n,&l,&g);
	for(int i=1; i<=n; i++) {
		int w,h;
		scanf("%d%d",&w,&h);
		judge(w,h);
	}

	return 0;
}
