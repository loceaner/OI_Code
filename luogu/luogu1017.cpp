//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
#include"bits/stdc++.h"//上一个题太勤快了，这一次要懒一点 
using namespace std;

int n,jie;
int a[50];

int main() {
	cin>>n>>jie;
	int hi=0;
	printf("%d=",n);
	while(n) {
		int sk=n%jie;
		if(sk<0)sk=sk-jie;
		n=(n-sk)/jie;
		a[++hi]=sk;
	}
	for(int i=hi; i; i--) {
		if(a[i]>=10) {
			printf("%c",a[i]-10+'A');
		} else printf("%d",a[i]);
	}
	printf("(base%d)\n",jie);
	return 0;
}
