//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node {
	int no,num;
	void fun(int _no,int _num) {
		no=_no,num=_num;
	}
};
int n,k;

void solve() {
	queue <node> q;
	node a;
	int cur=1,tmp;
	for(int i=1; i<=n; i++) {
		a.fun(i,cur);
		if(a.num>=40)  printf("%3d",i);
		else  q.push(a);
		cur=cur%k+1;
	}
	tmp=cur;
	while(!q.empty()) {
		node c=q.front();
		q.pop();
		if(c.num+tmp>=40) {
			printf("%3d",c.no);
			tmp=c.num+tmp-40;
		} else {
			c.num+=tmp;
			q.push(c);
			tmp=0;
		}
		if(tmp==0)  tmp=(cur++)%k+1;
	}
	printf("\n");
}

int main() {
	while(scanf("%d %d",&n,&k)!=EOF) {
		if(n==0 && k==0) break;
		solve();
	}
	return 0;
}
