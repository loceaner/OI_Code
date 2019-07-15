//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<map>
#include<list>
#include<cctype>
#include<vector>
#include<stack>//无敌缺省源
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,c,sjp=6666;
	scanf("%d",&n);
	for(int i=n; i>=0; i--) {
		scanf("%d",&c);
		if(c!=0) {
			if(i!=n&&c>0)
				printf("+");
			if(abs(c)>1||i==0)
				printf("%d",c);
			if(c==-1&&i!=0)
				printf("-");
			if(i>1)
				printf("x^%d",i);
			if(i==1)
				printf("x");
		}
	}
	return 0;
}

