//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

int size=0,n,m,num[100010];
priority_queue<int>sjp;

int clac(int a,int b,int c,int x) {
	return a*x*x+b*x+c;
}
int main() {
	int a,b,c;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1; i<=m; i++) {
		sjp.push(clac(a,b,c,i));
	}
	for(int i=2; i<=n; i++) {
		scanf("%d%d%d",&a,&b,&c);
		for(int j=1;j<=m;j++)
		{
			int ai=clac(a,b,c,j);
			if(i==1)sjp.push(ai);
		else {
			if(ai<sjp.top()) {
				sjp.push(ai);
				sjp.pop();
			} else
				break;
		}
		}	
	}
	for(int i=1; i<=m; i++) {
		num[i]=sjp.top();
		sjp.pop();
	}
	for(int i=m; i>=1; i--) {
		printf("%d ",num[i]);
	}
	return 0;
}
