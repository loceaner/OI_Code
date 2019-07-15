//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
#include<bits/stdc++.h>//s勾p的懒人万能头 
using namespace std;
char x;
long long coe,value,vivo=1;//vivo x27 真好 
double ans;
int main() {//s勾p的主函数啦~~ 
	char c=getchar();
	long long r=0,s=1;
	bool ten=false;
	while (true) {
		if (c>='a' && c<='z') {
			x=c;
			if (r==0 && !ten) coe+=vivo*s,ten=false;
			else coe+=vivo*s*r,r=0,s=1,ten=false;
		} else if (c=='-') value+=-vivo*s*r,r=0,s=-1,ten=false;
		else if (c=='+') value+=-vivo*s*r,r=0,s=1,ten=false;
		else if (c>='0' && c<='9') r=r*10+c-'0',ten=true;
		else if (c=='=') value+=-vivo*s*r,r=0,s=1,vivo=-vivo,ten=false;
		else {
			value+=-vivo*s*r;
			break;
		}
		c=getchar();
	}
	ans=double(value)/coe;
	printf("%c=%.3lf",x,ans==0?abs(ans):ans);
	return 0;
}
