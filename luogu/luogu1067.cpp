//s��p����ר�����
//ѧϰʹ�ҿ��֣����ҵ�������������
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
#include<stack>//�޵�ȱʡԴ
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

