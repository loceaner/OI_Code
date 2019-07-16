#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#define INF 2121212211
using namespace std;

struct node {
	string mi;
	int num;
} pre[2000011];

int find(int x) {
	if(pre[x].num==x)return x;
	return pre[x].num=find(pre[x].num);
}

int findx(string s) {
	int ans=0;
	for(int i=1; i<=20001; i++) {
		if(s==pre[i].mi)return i;
	}
}
int n,m;

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		pre[i].num=i;
		cin>>pre[i].mi;
	}
	for(int i=1; i<=m; i++) {
		string mi1,mi2;
		cin>>mi1>>mi2;
		int x=findx(mi1);
		int y=findx(mi2);
		int xx=find(pre[x].num);
		int yy=find(pre[y].num);
		if(xx!=yy) {
			pre[xx].num=yy;
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=1; i<=k; i++) {
		string mi1,mi2;
		cin>>mi1>>mi2;
		int x=findx(mi1);
		int y=findx(mi2);
		int xx=find(pre[x].num);
		int yy=find(pre[y].num);
		if(xx!=yy) printf("No.\n"); 
		else printf("Yes.\n");
	}
	return 0;
}
