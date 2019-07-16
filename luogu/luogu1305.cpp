#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

int n;
char s[50][4];

void find(char a) {//处理的函数
	if(a!='*') {
		cout<<a;
		for(int i=1; i<=n; i++) {
			if(s[i][1]==a) {
				find(s[i][2]);
				find(s[i][3]);
			}
		}
	}
}

int main() {//这是自己打的主函数谢谢
	cin>>n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=3; j++) {
			cin>>s[i][j];
		}
	}
	find(s[1][1]);
	return 0;
}
